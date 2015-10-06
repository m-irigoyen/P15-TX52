#include "Network.h"

Network::Network() : initialized(false)
{
}

bool Network::closeConnection()
{
	if (this->initialized)
	{
		this->client.disconnect();
		this->initialized = false;

		std::cout << "Network::closeConnection() : Disconnected" << std::endl;
		return true;
	}
	return false;
}

bool Network::sendData(string data)
{
	if (!this->initialized)
	{
		std::cout << "ERROR : Network::send : Socket connection hasn't been initialized. Aborting..." << std::endl;
		return false;
	}

	// Sending the data
	this->client.send(data.data(), data.length());

	return true;
}



bool Network::listen(int portNumber)
{
	// bind the listener to a port
	if (listener.listen(portNumber) != sf::Socket::Done)
	{
		std::cout << "ERROR : Network::listen : listening to port number " << portNumber << " failed. Aborting..." << std::endl;
		return false;
	}

	// accept a new connection
	if (listener.accept(client) != sf::Socket::Done)
	{
		std::cout << "ERROR : Network::listen : Couldn't accept client. Aborting..." << std::endl;
		return false;
	}

	std::cout << "Network::listen : Accepted connection on port " << portNumber << std::endl;
}

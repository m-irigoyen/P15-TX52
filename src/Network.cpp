#include "Network.h"

Network::Network() : initialized(false)
{
}

bool Network::closeConnection()
{
	if (this->initialized)
	{
		this->unitySocket.disconnect();
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
	this->unitySocket.send(data.data(), data.length());

	return true;
}

bool Network::receiveData(deque<string>* data)
{
	if (this->receivedMessages.empty())
		return false;

	// Transmitting messages
	*data = this->receivedMessages;
	this->receivedMessages.clear();
	return true;
}

void Network::cleanMessage(string& message)
{
	// Removing end spaces
	while (message.back() == ' ')
	{
		message.pop_back();
	}

	// Removing front spaces
	while (message.front() == ' ')
	{
		message.erase(message.begin());
	}
}

bool Network::initConnection(int portNumber)
{
	// bind the listener to a port
	if (listener.listen(portNumber) != sf::Socket::Done)
	{
		std::cout << "ERROR : Network::listen : listening to port number " << portNumber << " failed. Aborting..." << std::endl;
		return false;
	}

	// accept a new connection
	if (listener.accept(this->unitySocket) != sf::Socket::Done)
	{
		std::cout << "ERROR : Network::listen : Couldn't accept client. Aborting..." << std::endl;
		return false;
	}

	std::cout << "Network::listen : Accepted connection on port " << portNumber << std::endl;
}

void Network::listen()
{
	char data[100];
	std::size_t bytesReceived;

	if (this->unitySocket.receive(data, 100, bytesReceived) != sf::Socket::Done)
	{
		cout << "ERROR : Network::listen : Error receiving message. Aborting..." << endl;
		return;
	}

	std::cout << "Network::Listen : Received " << bytesReceived << " bytes" << endl;

	// Cleaning and formatting
	string message(data);
	this->cleanMessage(message);

	// Add to list of received
	this->receivedMessages.push_back(message);
}
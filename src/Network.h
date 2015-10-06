#ifndef NETWORK_H_
#define NETWORK_H_

#include <string>
#include <iostream>
#include "SFML\Network.hpp"

using namespace std;

class Network
{
public:
	Network();

	bool closeConnection();

	bool sendData(string data);
	bool listen(int portNumber);

private:
	sf::TcpSocket client;
	sf::TcpListener listener;
	bool initialized;
};


#endif


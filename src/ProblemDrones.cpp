#include "ProblemDrones.h"

ProblemDrones::ProblemDrones(std::map<int, DRONE_BEHAVIOURS> behaviourTable, int numberOfDrones)
{
}

void ProblemDrones::run(sf::Time elapsedTime)
{
	this->unityConnection.receiveData(&this->messages);

	while (!messages.empty())
	{
		std::cout << "Message : " << messages.front() << std::endl;
		messages.pop_front();
	}
}

bool ProblemDrones::init(int portNumber)
{
	return this->unityConnection.initConnection(portNumber);
}

int ProblemDrones::getNumberOfDrones()
{
	return this->nbDrones;
}

void ProblemDrones::setDroneOrder(int droneId, droneOrder order)
{
	if (this->droneCommands.count(droneId) == 0)
		this->droneCommands.insert(pair<int, droneOrder>(droneId, order));
	else
	{
		//TODO : finish this
		//this->droneCommands.find(droneId)
	}

}

// Gets corresponding behaviour to given frequency
DRONE_BEHAVIOURS ProblemDrones::getBehaviour(int frequency)
{
	// Go through the look up table of behaviours
	for (map<int, DRONE_BEHAVIOURS>::iterator it = this->behaviourTable.begin(); it != this->behaviourTable.end(); ++it)
	{
		// We went too far : frequency is now smaller than the one we're looking at
		if (frequency >= it->first-FREQUENCY_MARGIN_D && frequency <= it->first + FREQUENCY_RANGE_D + FREQUENCY_MARGIN_D)
		{
			return it->second;
		}
	}
	
	return DRONE_BEHAVIOURS::hover;
}

DRONE_BEHAVIOURS ProblemDrones::getBehaviour(float frequency)
{
	return this->getBehaviour((int) frequency);
}

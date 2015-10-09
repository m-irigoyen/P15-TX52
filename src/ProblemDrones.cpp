#include "ProblemDrones.h"

ProblemDrones::ProblemDrones(std::map<int, int> behaviourTable, int numberOfDrones)
{
}

void ProblemDrones::run(sf::Time elapsedTime)
{
	//this->
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
		if (frequency >= it->first-100 && frequency <= it->first + 1000)
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

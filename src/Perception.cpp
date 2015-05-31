#include "Perception.h"

Perception::Perception()
{

}

// Adds that new wave to the list
void Perception::addNewWave(int emitterId, sf::Time contact, float amplitude)
{
	std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator it = this->percievedWaves.find(emitterId);
	if (it != this->percievedWaves.end())
	{
		// A wave with that id already exists
		//TODO: merge the stuff
		std::cout << "Perception::addNewWave : found corresponding id" << std::endl;
		sf::Time tempFrequency = contact - it->second.first;	// Calculating frequency for given wave
		it->second.second.first = tempFrequency.asSeconds();	// Setting frequency
		it->second.second.second = amplitude;
	}
	else
	{
		this->percievedWaves.insert
			(
			std::pair<int, std::pair<sf::Time, std::pair<float, float>>>(emitterId, std::pair<sf::Time, std::pair<float, float>>(contact, std::pair<float, float>(-1.0f, amplitude)))
			);

		std::cout << "Perception::addNewWave : first time encountering this id" << std::endl;
	}
}

// Removes given id from the list
void Perception::removeWave(int emitterId)
{
	std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator it = this->percievedWaves.find(emitterId);
	if (it != this->percievedWaves.end())
		this->percievedWaves.erase(it);
}

std::map<int, std::pair<sf::Time, std::pair<float, float>>>* Perception::getWaves()
{
	return &this->percievedWaves;
}
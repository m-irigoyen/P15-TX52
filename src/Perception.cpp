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
		//std::cout << "Perception::addNewWave : found corresponding id" << std::endl;
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

		//std::cout << "Perception::addNewWave : first time encountering this id" << std::endl;
	}
}

// Removes given id from the list
void Perception::removeWave(int emitterId)
{
	std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator it = this->percievedWaves.find(emitterId);
	if (it != this->percievedWaves.end())
		this->percievedWaves.erase(it);
}

// Return an iterator to before and after that time
void Perception::getEncasingIterators(sf::Time t, bool& exactMatch,
        std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator& itBefore,
        std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator& itAfter)
{
    std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator it = findByTime(t);


    if (it != this->percievedWaves.end())   // Case 1 : found an exact match
    {
        exactMatch = true;
        itBefore = it;
        itAfter = it;
        return;
    }
    else if (t < (*this->percievedWaves.begin()).second.first) // Case 2 : t older than oldest element
    {
        exactMatch = false;
        itBefore = this->percievedWaves.begin();
        itAfter = this->percievedWaves.begin();
        return;
    }
    else if (this->percievedWaves.size() >= 1 &&
		t > (this->percievedWaves.at(this->percievedWaves.size() - 1)).first
            )   // Case 3 : t newer than newest perception element
    {
        exactMatch = false;
        itBefore = this->percievedWaves.end();
        itAfter = this->percievedWaves.end();
        return;
    }



    // Last case : t must be contained within perceptions. So t > begin, and t < end
    int i = 0;
    for (it = this->percievedWaves.begin(); it != this->percievedWaves.end(); ++it)
    {
		if (t < (*it).second.first)   // We passed t
        {
            exactMatch = false;
            itAfter = it;
            itBefore = --it;
            return;
        }

        ++i;
    }
}

std::map<int, std::pair<sf::Time, std::pair<float, float>>>* Perception::getWaves()
{
	return &this->percievedWaves;
}

// Private methods
std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator Perception::findByTime(sf::Time t)
{
	for (
		std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator it = this->percievedWaves.begin();
		it != this->percievedWaves.end();
		++it
		)
	{
		if (it->second.first == t)
			return it;
	}
}

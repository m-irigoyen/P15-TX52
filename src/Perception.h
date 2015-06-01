#ifndef PERCEPTION_H_
#define PERCEPTION_H_

/*
*   A Perception object is constructed by the environment to represent all the wavelengths that a Body percieves.
*   For each wave percieved by a body, there will be one Perception object
*/

#include <iostream>
#include <map>
#include<vector>
#include <SFML/System/Time.hpp>

struct WAVE_COMPOSITION
{
	float frequency;
	float amplitude;
};

class Perception
{
private:

	/*!
		This map stores each percieved wave.
		When a wave is percieved and has an unknown emitter id, just add it
		emitterId = firstContact, frequency, amplitude
	*/
	std::map<int, std::pair<sf::Time, std::pair<float, float>>> percievedWaves;
	std::vector<float> computedValues;


public:
    Perception();

	void addNewWave(int emitterId, sf::Time firstContact, float amplitude);	// Adds that new wave to the list
	void removeWave(int emitterId);	// Removes given id from the list

	void getEncasingIterators(sf::Time t, bool& exactMatch,
        std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator& itBefore,
        std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator& itAfter);  // Return an iterator to before and after that time

	std::map<int, std::pair<sf::Time, std::pair<float, float>>>* getWaves();
};

#endif

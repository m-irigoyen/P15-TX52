#ifndef RECEPTOR_H_
#define RECEPTOR_H_

/*
* Receptor is the abstract interface
*/

#include <deque>
#include "Perception.h"


class Receptor
{
protected:
	Perception perception;
	std::deque<std::pair<sf::Time, float>> computedValues;

    sf::Time memoryTime;


public:
	Receptor();

	virtual void initialise() = 0;	// Initialises the receptor
	virtual WAVE_COMPOSITION getPerception() = 0;    // Returns what the receptor can make of all it has recieved. #PHYSICS STUFF
	virtual void onWaveCollision(int emitterId, sf::Time contact, float amplitude);

	virtual float calculateValueAtT(sf::Time t) = 0;    // Calculates value for result wave at given time
	virtual float calculateValueAtT(sf::Time t, sf::Time firstContact, float frequency, float amplitude) = 0;    // Calculates value for given wave at given time

	virtual std::deque<std::pair<sf::Time, float>>* getComputedValues();
	virtual void updateComputedValues(sf::Time currentTime) = 0;

    virtual sf::Time getMemoryTime();
};

#endif

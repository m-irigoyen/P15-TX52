#ifndef BODYRECEPTOR_H_
#define BODYRECEPTOR_H_

#include "Body.h"
#include "Receptor.h"

/*
* Receptor bodies can percieve waves in the world.
* This is the base class for all receptors
*/

class BodyReceptor:  public Body, public Receptor
{
protected: 


public:
	BodyReceptor(Semantic type, float x, float y);

	//Receptor functions
	virtual void initialise() = 0;	// Initialises the receptor
	virtual WAVE_COMPOSITION getPerception() = 0;    // Returns what the receptor can make of all it has recieved. #PHYSICS STUFF

	//Body functions
    virtual void update(sf::Time elapsedTime) = 0;

};

#endif

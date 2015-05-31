#ifndef BODYRECEPTORCOMPOSITION_H_
#define BODYRECEPTORCOMPOSITION_H_

#include "BodyReceptor.h"

/*
* Receptor bodies can percieve waves in the world.
* This is the base class for all receptors
*/



class BodyReceptorComposition : public BodyReceptor
{
public:
	BodyReceptorComposition(Semantic type, float x, float y);

	//Receptor functions
	virtual void initialise();	// Initialises the receptor
	virtual WAVE_COMPOSITION getPerception();    // Returns what the receptor can make of all it has recieved. #PHYSICS STUFF

	

	//Body functions
	virtual void update(sf::Time elapsedTime);

protected:
	WAVE_COMPOSITION currentPerception;
	std::vector<float> values;
};

#endif

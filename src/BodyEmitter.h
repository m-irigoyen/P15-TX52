#ifndef BODYEMITTER_H_
#define BODYEMITTER_H_

// This is an interface
/*
*	Emitters can send waves in the world.
*/

#include "Body.h"
#include "Emitter.h"


//FIXME : Problem of refresh rate to send waves. Maybe add a timeToSend in send, so the world can already place the wave at the correct position accounting for the time that has passed
class BodyEmitter : public Body, public Emitter
{
public:
	BodyEmitter(Semantic type, float x, float y);

	virtual void initialise();

	// Body methods
    virtual void update(sf::Time elapsedTime);
};

#endif

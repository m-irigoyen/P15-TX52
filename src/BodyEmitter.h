#ifndef BODYEMITTER_H_
#define BODYEMITTER_H_

#include "Body.h"

/*
*	Emitters can send waves in the world.
*/

class BodyEmitter:  public Body
{
private:

public:
	BodyEmitter(Semantic type);

    void send(float frequency, float amplitude);

	~BodyEmitter(void);
};

#endif

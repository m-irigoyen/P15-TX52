#ifndef BODYEMITTER_H_
#define BODYEMITTER_H_

#include "BodyReceptor.h"

/*
*	Emitters can send waves in the world.
*/

class BodyEmitter:  public BodyReceptor
{
private:

public:
	BodyEmitter(Semantic type, World* world);

    void send(float frequency, float amplitude);

	~BodyEmitter(void);
};

#endif

#ifndef BODYEMITTER_H_
#define BODYEMITTER_H_

#include "BodyReceptor.h"

/*
*
*/

class BodyEmitter:  public BodyReceptor
{
private:

public:
	BodyEmitter(Semantic type);

    void createWave(float waveLength);

	~BodyEmitter(void);
};

#endif

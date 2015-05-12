#ifndef BODY_RECEPTOR_H_
#define BODY_RECEPTOR_H_

#include "Body.h"

/*
* Receptor bodies can percieve waves in the world. When they percieve multiple waves, they use wave superposition to determine the final result.
*/

class BodyReceptor:  public Body
{
private:

public:
	BodyReceptor(Semantic type, World* world);

    Perception GetPerception();    // Returns a list of percieved waves
    virtual void update(int elapsedTime);

	~BodyReceptor(void);
};

#endif

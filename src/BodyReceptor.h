#ifndef BODY_RECEPTOR_H_
#define BODY_RECEPTOR_H_

#include "Body.h"

/*
*
*/

class BodyReceptor:  public Body
{
private:

public:
	BodyReceptor(Semantic type);

    virtual std::vector<Perception> GetPerception();    // Returns a list of percieved waves
    virtual void update(float dt);

	~BodyReceptor(void);
};

#endif

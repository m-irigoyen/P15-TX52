#ifndef BODY_H_
#define BODY_H_

#include <vector>

#include "PhysicalObject.h"
#include "Perception.h"

/*
*   A Body is a PhysicalObject that can percieve things from the environment, and is linked to an agent.
*   The Agent is the brain, and will give commands to the Body.
*   Here ,the Body can send waves and recieve Perceptions from the environment.
*/

class Body:  public PhysicalObject
{
private:

public:
	Body(Semantic type, World* world);

	virtual void update(int elapsedTime) = 0;

	~Body(void);
};

#endif

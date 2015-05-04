#ifndef AGENT_H_
#define AGENT_H_

#include "Body.h"

class Agent
{
private:
	Body* body;
	Agent(void) {}

public:
	Agent(Body* body);

	virtual void Life() = 0;

	~Agent(void);
};

#endif
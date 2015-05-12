#ifndef AGENTRECEPTOR_H_
#define AGENTRECEPTOR_H_

#include "Agent.h"

/*
*   AgentReceptors recieve waves in the environment, and in turn act on the problem (drone, pendulum, etc)
*/

class AgentReceptor : public Agent
{
private:
	Body* body;
	AgentReceptor(void) {}

public:
	AgentReceptor(Body* body);

	virtual void Live();

	~AgentReceptor(void);
};

#endif

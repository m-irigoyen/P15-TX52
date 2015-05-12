#ifndef AGENTRECEPTOR_H_
#define AGENTRECEPTOR_H_

#include "Agent.h"

/*
*   AgentReceptors recieve waves in the environment, and in turn act on the problem (drone, pendulum, etc)
*/

class AgentReceptor : public Agent
{
protected:

public:
	AgentReceptor(Problem* problem, Body* body = NULL);

	virtual void live();

	~AgentReceptor(void);
};

#endif

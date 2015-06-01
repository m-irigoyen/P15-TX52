#ifndef AGENTEMITTER_H_
#define AGENTEMITTER_H_

#include "Agent.h"

/*
*   AgentEmitters emit waves. They percieve the state of the problem (pendulum, drone, etc), and emit waves into the environment.
*/

class AgentEmitter : public Agent
{
protected:
    int state;

public:
	AgentEmitter(Problem* problem, Body* body = NULL, state = 0);

	virtual void live();

	~AgentEmitter(void);
};

#endif

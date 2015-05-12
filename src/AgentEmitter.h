#ifndef AGENTEMITTER_H_
#define AGENTEMITTER_H_

#include "Agent.h"

/*
*   AgentEmitters emit waves. They percieve the state of the problem (pendulum, drone, etc), and emit waves into the environment.
*/

class AgentEmitter : public Agent
{
private:
	Body* body;
	AgentEmitter(void) {}

public:
	AgentEmitter(Body* body);

	virtual void Live();

	~AgentEmitter(void);
};

#endif

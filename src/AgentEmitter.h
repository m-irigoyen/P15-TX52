#ifndef AGENTEMITTER_H_
#define AGENTEMITTER_H_

#include "Agent.h"

/*
*   AgentEmitters emit waves. They percieve the state of the problem (pendulum, drone, etc), and emit waves into the environment.
*/

class AgentEmitter : public Agent
{
protected:
	BodyEmitter* castBody;
public:
	AgentEmitter(Problem* problem, Body* body = NULL);

	virtual void live();

	~AgentEmitter(void);
};

#endif

#ifndef AGENT_H_
#define AGENT_H_

#include "Body.h"
#include "Problem.h"

/*
*   Agents are connected with Bodies. Agents are the mind, Bodies are the matter.
*   An Agent can be linked to only one Body. The agent has a life cycle of 3 steps :
*   1 - Percieve : ask it's Body what it percieves from the environment
*   2 - Think : using these perceptions, the Agent decides what to do next.
*   3 - Act : The Agents asks the Body to carry out this action.
*
*   The Agents will need to have a way to know the system's state (pendulum, drone, etc).
*/

class Agent
{
protected:
	Body* body;
	Problem* problem;

public:
	Agent(Problem* problem = NULL, Body* body = NULL);

	virtual void live() = 0;

	virtual void connect(Body* body);
	virtual void disconnect();

	virtual void setProblem(Problem* problem);
	Problem* getProblem();

	~Agent(void);
};

#endif

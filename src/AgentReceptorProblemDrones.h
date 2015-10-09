#ifndef AGENTRECEPTORPROBLEMDRONES_H_
#define AGENTRECEPTORPROBLEMDRONES_H_

#define DEBUG_AGENTRECEPTORPROBLEMDRONES 1

#include "AgentReceptor.h"
#include "ProblemDrones.h"

/*
*   AgentReceptors recieve waves in the environment, and in turn act on the problem (drone, pendulum, etc)
*/

class AgentReceptorProblemDrones : public AgentReceptor
{
protected:
	ProblemDrones* castedProblem;

public:
	AgentReceptorProblemDrones(ProblemDrones* problem, BodyReceptorComposition* body = NULL);

	virtual void live();

	~AgentReceptorProblemDrones(void);
};

#endif

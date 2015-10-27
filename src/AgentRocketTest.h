#ifndef AGENTROCKETTEST_H_
#define AGENTROCKETTEST_H_

#include "Agent.h"
#include "ProblemRocket.h"

class AgentRocketTest : public Agent
{
protected:
	ProblemRocket* castedProblem;

public:
	AgentRocketTest(ProblemRocket* problem);

	virtual void live();
};

#endif
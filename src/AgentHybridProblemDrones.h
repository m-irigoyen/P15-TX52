#ifndef AGENTHYBRIDPROBLEMDRONES_H_
#define AGENTHYBRIDPROBLEMDRONES_H_

#include "ProblemDrones.h"
#include "AgentHybrid.h"

/*
*   Hybrid for the ProblemPointer
*/

class AgentHybridProblemDrones : public AgentHybrid
{
protected:
	ProblemDrones* castedProblem;

public:
	AgentHybridProblemDrones(ProblemDrones* problem, BodyHybrid* body = NULL);

	virtual void live();

	~AgentHybridProblemDrones(void);
};

#endif

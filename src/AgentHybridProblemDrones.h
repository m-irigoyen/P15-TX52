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
	int droneId;

public:
	AgentHybridProblemDrones(ProblemDrones* problem, BodyHybrid* body = NULL, int droneId = -1);

	virtual void live();

	void connectEmitter();

	~AgentHybridProblemDrones(void);
};

#endif

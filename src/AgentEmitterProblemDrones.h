#ifndef AGENTEMITTERPROBLEMDRONES_H_
#define AGENTEMITTERPROBLEMDRONES_H_

#include "AgentEmitter.h"
#include "ProblemDrones.h"

#define DEBUG_AGENTEMITTERPROBLEMDRONES 1

/*
*   Emitter for the ProblemPointer
*/

class AgentEmitterProblemDrones : public AgentEmitter
{
protected:
	ProblemDrones* castedProblem;

public:
	AgentEmitterProblemDrones(ProblemDrones* problem, BodyEmitter* body = NULL);

	virtual void live();

	~AgentEmitterProblemDrones(void);
};

#endif

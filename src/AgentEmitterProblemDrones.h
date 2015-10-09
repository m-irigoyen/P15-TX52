#ifndef AGENTEMITTERPROBLEMDRONES_H_
#define AGENTEMITTERPROBLEMDRONES_H_

#include "AgentEmitter.h"
#include "ProblemPointer.h"

#define DEBUG_AGENTEMITTERPROBLEMDRONES 1

/*
*   Emitter for the ProblemPointer
*/

class AgentEmitterProblemDrones : public AgentEmitter
{
protected:
	ProblemPointer* castedProblem;

public:
	AgentEmitterProblemDrones(ProblemPointer* problem, BodyEmitter* body = NULL);

	virtual void live();
	virtual bool isLinked();	// Checks if agent is linked to a body
	virtual bool isProblemLinked();

	~AgentEmitterProblemDrones(void);
};

#endif

#include "AgentEmitterProblemDrones.h"

AgentEmitterProblemDrones::AgentEmitterProblemDrones(ProblemDrones * problem, BodyEmitter * body) : AgentEmitter(problem, body)
{
	this->castedProblem = problem;
}

void AgentEmitterProblemDrones::live()
{
}

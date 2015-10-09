#include "AgentReceptorProblemPointer.h"
#include "AgentReceptorProblemDrones.h"

AgentReceptorProblemDrones::AgentReceptorProblemDrones(ProblemDrones * problem, BodyReceptorComposition * body) : AgentReceptor(problem, body)
{
	this->castedProblem = problem;
}

void AgentReceptorProblemDrones::live()
{
}

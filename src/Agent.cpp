#include "Agent.h"


Agent::Agent(Problem* problem, Body* body) : problem(problem), body(body)
{
}

Agent::~Agent(void)
{
}

void Agent::connect(Body* body)
{
	this->body = body;
}

void Agent::disconnect()
{
	this->body = NULL;
}

void Agent::setProblem(Problem* problem)
{
	this->problem = problem;
}

Problem* Agent::getProblem()
{
	return this->problem;
}
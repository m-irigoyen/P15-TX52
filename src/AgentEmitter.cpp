#include "AgentEmitter.h"

AgentEmitter::AgentEmitter(Problem* problem, Body* body) : Agent(problem, body)
{
    this->state = state;
}

void AgentEmitter::live()
{
	((BodyEmitter*)this->body)->send(10.0f,1.0f);
}

#include "AgentEmitter.h"

AgentEmitter::AgentEmitter(Problem* problem, Body* body) : Agent(problem, body)
{
	castBody = static_cast<BodyEmitter*>(body);
}

void AgentEmitter::live()
{
	BodyEmitter* temp = dynamic_cast<BodyEmitter*>(body); 
	temp->send(1, 1);
}
#include "AgentEmitter.h"
#define FREQUENCY 2.0

AgentEmitter::AgentEmitter(Problem* problem, BodyEmitter* body) : Agent(problem, body), castedBody(body)
{
    //this->state = state;
	connectCasted(body);
}

void AgentEmitter::live()
{
	//((BodyEmitter*)this->body)->send(1.0f,1.0f);
}

AgentEmitter::~AgentEmitter(void)
{
	Agent::connect(body);
}

void AgentEmitter::connectCasted(BodyEmitter* body)
{
	if (body != NULL)
	{
		Agent::connect(body);
		this->castedBody = body;
	}
}

void AgentEmitter::disconnect()
{
	Agent::disconnect();
	this->castedBody = NULL;
}

#include "AgentReceptor.h"

AgentReceptor::AgentReceptor(Problem* problem, Body* body) : Agent(problem, body)
{

}

void AgentReceptor::live()
{
    Perception p = ((BodyEmitter)*this->body).getPerception();

    ((Pendulum)*this->problem).act(-1*p.amplitude);
}

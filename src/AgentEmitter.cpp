#include "AgentEmitter.h"

AgentEmitter::AgentEmitter(Problem* problem, Body* body = NULL, state = 0) : Agent(problem, body)
{
    this->state = state;
}

void AgentEmitter::live()
{
    double amplitude = 0;
    switch(this->state){
        case 0:
            amplitude = ((Pendulum)*this->problem).getSpeed();
            break;
        case 1:
            amplitude = ((Pendulum)*this->problem).getAngle();
            break;
    }

    ((BodyEmitter)*body).send(amplitude,2.0);
}

#include "BodyReceptor.h"

BodyReceptor::BodyReceptor(Semantic type)
{

}

    // Returns a list of percieved waves
std::vector<Perception> BodyReceptor::GetPerception()
{
    return this->world->getPerception(this);
}

void BodyReceptor::update(float dt)
{

}

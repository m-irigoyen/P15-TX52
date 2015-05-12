#include "BodyReceptor.h"

BodyReceptor::BodyReceptor(Semantic type, World* world) : Body(type, world)
{

}

    // Returns a list of percieved waves
Perception BodyReceptor::GetPerception()
{
	//TODO:
	return Perception(0, 0.0f);
}

void BodyReceptor::update(int elapsedTime)
{

}

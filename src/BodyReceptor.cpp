#include "BodyReceptor.h"

BodyReceptor::BodyReceptor(Semantic type) : Body(type)
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

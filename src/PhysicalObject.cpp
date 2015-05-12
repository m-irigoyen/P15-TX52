#include "PhysicalObject.h"


PhysicalObject::PhysicalObject(Semantic type, World* world) : world(world), type(type)
{
	
}


PhysicalObject::~PhysicalObject(void)
{
}

void PhysicalObject::SetPosition(float x, float y)
{
	this->posX = x;
	this->posY = y;
}

void PhysicalObject::GetPosition(float &x, float &y)
{
	x = this->posX;
	y = this->posY;
}

std::vector<float> PhysicalObject::GetPosition()
{
	std::vector<float> ret;
	ret.push_back(this->posX);
	ret.push_back(this->posY);
	return ret;
}

void PhysicalObject::SetSemantic(Semantic type)
{
	this->type = type;
}

Semantic* PhysicalObject::GetSemantic()
{
	return &this->type;
}

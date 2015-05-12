#include "World.h"


World::World(void)
{
}

//TODO: finish that
Body* World::CreateBody(BODY_TYPE bodyType)
{
    Body* body;
    switch (bodyType)
    {
	case BODY_TYPE::EMITTER :
            body = new BodyEmitter(Semantic(Tags::emitter), this);
            break;
	case BODY_TYPE::RECEPTOR :
            body = new BodyEmitter(Semantic(Tags::receptor), this);
            break;
    }
	//this->listOfPhysicalObjects.push_back(body);
	//body = static_cast<Body*>(this->listOfPhysicalObjects.at(this->listOfPhysicalObjects.size()-1));
	this->listOfBodys.push_back(body);
	return body;
}


std::vector<PhysicalObject*>* World::GetListOfPhysicalObjects()
{
	return &this->listOfPhysicalObjects;
}

std::vector<Body*>* World::GetListOfBodys()
{
	return &this->listOfBodys;
}

World::~World(void)
{
}

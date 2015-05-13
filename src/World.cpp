#include "World.h"

World::World(void)
{

}

Body* World::createBody(BODY_TYPE bodyType, float xPos, float yPos)
{
    Body* body;
    switch (bodyType)
    {
	case BODY_TYPE::EMITTER :
            body = new BodyEmitter(Semantic(Tags::emitter), this);
            this->emitters.push_back(body);
            break;
	case BODY_TYPE::RECEPTOR :
            body = new BodyEmitter(Semantic(Tags::receptor), this);
            this->receptors.push_back(body);
            break;
    }
	//this->listOfPhysicalObjects.push_back(body);
	//body = static_cast<Body*>(this->listOfPhysicalObjects.at(this->listOfPhysicalObjects.size()-1));
	body->SetPosition(xPos, yPos);
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

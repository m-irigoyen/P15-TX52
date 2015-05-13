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
            this->emitters.push_back(body);
            break;
	case BODY_TYPE::RECEPTOR :
            body = new BodyEmitter(Semantic(Tags::receptor), this);
            this->receptors.push_back(body);
            break;
    }
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

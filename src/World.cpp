#include "World.h"

World::World(void)
{
    this->receptors.clear();
}

Body* World::createBody(BODY_TYPE bodyType, float xPos, float yPos)
{
    Body* body;
    switch (bodyType)
    {
	case BODY_TYPE::EMITTER :
            this->emitters.push_back(new BodyEmitter(Semantic(Tags::emitter)));
            body = static_cast<Body*>(this->emitters.at(this->emitters.size()-1));
            break;
	case BODY_TYPE::RECEPTOR :
            this->receptors.push_back(new BodyReceptor(Semantic(Tags::receptor)));
            body = static_cast<Body*>(this->receptors.at(this->receptors.size()-1));
            break;
	default:	// If that happens, something's wrong
		std::cout << "ERROR : body creation : unknown bodyType" << endl;
		this->receptors.push_back(new BodyReceptor(Semantic(Tags::receptor)));
		body = static_cast<Body*>(this->receptors.at(this->receptors.size() - 1));
    }
	body->SetPosition(xPos, yPos);
	return body;
}

Wave* World::createWave(int id, float waveLength) //TODO: finish that
{
	return NULL;
}

std::vector<Wave*>* World::getWaves()
{
	return &this->waves;
}

std::vector<BodyEmitter*>* World::getEmitters()
{
    return &this->emitters;
}

std::vector<BodyReceptor*>* World::getReceptors()
{
    return &this->receptors;
}

World::~World(void)
{
}

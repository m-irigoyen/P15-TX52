#include "World.h"

World::World(sf::Clock* clock) : simulationClock(clock)
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
            this->receptors.push_back(new BodyReceptorComposition(Semantic(Tags::receptor)));
            body = static_cast<Body*>(this->receptors.at(this->receptors.size()-1));
            break;
	default:	// If that happens, something's wrong
		std::cout << "ERROR : body creation : unknown bodyType" << endl;
		this->receptors.push_back(new BodyReceptorComposition(Semantic(Tags::receptor)));
		body = static_cast<Body*>(this->receptors.at(this->receptors.size() - 1));
    }
	body->SetPosition(xPos, yPos);
	return body;
}

/*
	This function create a new wave
	Return type : Wave*

	x				X position for the wave
	y				Y position for the wave
	radius			radius value for the wave
	frequency		frequency value for the wave
	speed			speed value for the wave
	amplitude		amplitude value for the wave
*/

Wave* World::createWave(float x, float y, float radius, float frequency, float speed, float amplitude)
{

	// Create a wave
	Wave * wave = new Wave(Semantic(Tags::wave));
	// Initialize the wave
	wave->initWave(x, y, radius, frequency, speed, amplitude);

	this->waves.push_back(wave);

	// return it
	return wave;
}

/*
Update each element contained in the world at each execution loop (based on the time not the frame)
Return : void
*/
void World::update(sf::Time elapsedTime)
{
	// Updating emitters
	for (std::vector<BodyEmitter*>::iterator it = this->emitters.begin();
		it != this->emitters.end();
		++it)
	{
		//TODO: check for wave creations
		(*it)->update(elapsedTime);
	}

	elapsedTime.asSeconds();

	//Updating waves
	for (std::vector<Wave*>::iterator it = this->waves.begin();
		it != this->waves.end();
		++it)
	{
		(*it)->update(elapsedTime);
		if ((*it)->getRadius() > this->maxWaveDistance)	// If the wave has reached max distance : erase it
			it = this->waves.erase(it);
		else
			checkCollisionEvents((*it), elapsedTime);	// Else, check for collisions
	}

	// updating receptors
	for (std::vector<BodyReceptor*>::iterator it = this->receptors.begin();
		it != this->receptors.end();
		++it)
	{
		(*it)->update(elapsedTime);
		(*it)->
	}


	//FIXME : remove that
	int cursor;

	for (cursor = 0; cursor < waves.size(); ++cursor)
	{
		//TODO : Add the elasped time
		//waves.at(cursor)->update();
	}

	for (cursor = 0; cursor < receptors.size(); ++cursor)
	{
		updateReceptor(receptors.at(cursor));
	}
}

/*
For a specific receptor, look for each wave colliding with it, then set the receptor in consequences
*/
void World::updateReceptor(BodyReceptor* receptor)
{
	//TODO get the perception for the receptor
	//TODO set the body in function of its perception
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

//Private
void World::checkCollisionEvents(Wave* wave, sf::Time elapsedTime)
{
	float minDistance = wave->getRadius() - wave->getSpeed()*elapsedTime.asSeconds();
	float maxDistance = wave->getRadius();

	float x1, xWave, y1, yWave;
	wave->GetPosition(xWave, yWave);


	for (std::vector<BodyReceptor*>::iterator it = this->receptors.begin();
		it != this->receptors.end();
		++it)
	{
		(*it)->GetPosition(x1, y1);
		if (distanceCheck(x1, y1, xWave, yWave, minDistance, maxDistance))
		{
			if (!wave->hasCollided((*it)->getId()))
			{
				wave->onCollisionEvent((*it)->getId());
				(*it)->onWaveCollision(wave->getEmitterId(), simulationClock->getElapsedTime(), wave->getAmplitude());
			}
		}
	}
}

bool World::distanceCheck(float x1, float y1, float x2, float y2, float minDistance, float maxDistance)
{
	float distanceBetweenPoints = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (distanceBetweenPoints > maxDistance || distanceBetweenPoints < minDistance)
		return false;
	return true;

}
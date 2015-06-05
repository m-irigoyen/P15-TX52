#include "World.h"

World::World(sf::Clock* clock, float worldLength, float worldHeight) : simulationClock(clock), maxWaveDistance(0.0f), optimiseWaveTravelDistance(true)
{
    this->receptors.clear();
    this->maxWorldDistance = calculateDistance(0,0, worldLength, worldHeight);
}

bool World::toggleWaveOptimisation()
{
    if (this->optimiseWaveTravelDistance)
        this->optimiseWaveTravelDistance = false;
    else
        this->optimiseWaveTravelDistance = true;

    return this->optimiseWaveTravelDistance;
}

Body* World::getClosestBodyFromLocation(float x, float y, float rangeThreshold)
{
    Body* ret = NULL;
    float distance = rangeThreshold;
    float tempDistance;
    for (std::vector<BodyEmitter*>::iterator it = this->emitters.begin(); it != this->emitters.end(); ++it)
    {
        tempDistance = calculateDistance(x,y,(*it)->GetPosition());
        if (tempDistance < distance)
        {
            distance = tempDistance;
            ret = (*it);
        }
    }

    for (std::vector<BodyReceptor*>::iterator it = this->receptors.begin(); it != this->receptors.end(); ++it)
    {
        tempDistance = calculateDistance(x,y,(*it)->GetPosition());
        if (tempDistance < distance)
        {
            distance = tempDistance;
            ret = (*it);
        }
    }

    return ret;
}

Body* World::createBody(BODY_TYPE bodyType, float xPos, float yPos)
{
    Body* body;
	BodyReceptorComposition* tempBodyReceptor;
	BodyEmitter* tempBodyEmitter;
    switch (bodyType)
    {
	case BODY_TYPE::EMITTER :
		tempBodyEmitter = new BodyEmitter(Semantic(Tags::emitter), xPos, yPos);
		body = tempBodyEmitter;
		this->emitters.push_back(tempBodyEmitter);
        break;
	case BODY_TYPE::RECEPTOR :
		tempBodyReceptor = new BodyReceptorComposition(Semantic(Tags::receptor), xPos, yPos);
		body = tempBodyReceptor;
		this->receptors.push_back(tempBodyReceptor);
        break;
    }

	//updating maxWaveDistance
	updateMaxWaveDistance();

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

Wave* World::createWave(float x, float y, int emitterId, float speed, float amplitude)
{
	if (speed == -1.0f)
		speed = DEFAULT_PROPAGATION_SPEED;
	// Create a wave
	Wave * wave = new Wave(Semantic(Tags::wave), x, y, emitterId, speed, amplitude);
	this->waves.push_back(wave);

	// return it
	return wave;
}

Wave* World::createWave(std::vector<float> position, int emitterId, float speed, float amplitude)
{
	return createWave(position.at(0), position.at(1), emitterId, speed, amplitude);
}

/*
Update each element contained in the world at each execution loop (based on the time not the frame)
Return : void
*/
void World::update(sf::Time elapsedTime, sf::Time currentFrameTime)
{
	this->currentFrameTime = currentFrameTime;
	// Updating emitters
	for (std::vector<BodyEmitter*>::iterator it = this->emitters.begin();
		it != this->emitters.end();
		++it)
	{
		(*it)->update(elapsedTime);
		checkWaveCreation((*it));
	}

	elapsedTime.asSeconds();

	//Updating waves
	for (std::vector<Wave*>::iterator it = this->waves.begin();
		it != this->waves.end();
		++it)
	{
		(*it)->update(elapsedTime);
		checkCollisionEvents((*it), elapsedTime);	// Else, check for collisions
		if (optimiseWaveTravelDistance && (*it)->getRadius() > this->maxWaveDistance)	// If the wave has reached max distance : erase it
		{
            //std::cout << "OUAIS SALUT OUAIS " << std::endl;
			it = this->waves.erase(it);
		}
		else if ((*it)->getRadius() > this->maxWorldDistance)
		{
            it = this->waves.erase(it);
		}
	}

	// updating receptors
	for (std::vector<BodyReceptor*>::iterator it = this->receptors.begin();
		it != this->receptors.end();
		++it)
	{
		(*it)->update(elapsedTime);
		setPerception((*it));
	}
}

/*
For a specific receptor, look for each wave colliding with it, then set the receptor in consequences
*/
void World::setPerception(BodyReceptor* receptor)
{
	//receptor->updateComputedValues(this->currentFrameTime);
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
				(*it)->onWaveCollision(wave->getEmitterId(), this->currentFrameTime, wave->getAmplitude());
			}
		}
	}
}

bool World::distanceCheck(float x1, float y1, float x2, float y2, float minDistance, float maxDistance)
{
	float distanceBetweenPoints = calculateDistance(x1, y1, x2, y2);
	if (distanceBetweenPoints > maxDistance || distanceBetweenPoints < minDistance)
		return false;
	return true;
}

float World::calculateDistance(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

float World::calculateDistance(std::vector<float> pos1, std::vector<float> pos2)
{
	return calculateDistance(pos1.at(0), pos1.at(1), pos2.at(0), pos2.at(1));
}

float World::calculateDistance(float x1, float y1, std::vector<float> pos2)
{
    return calculateDistance(x1,y1, pos2.at(0), pos2.at(1));
}

// Calculates and sets the max wave distance
void World::updateMaxWaveDistance()
{
	float maxDistance = 0.0f;
	float tempDistance = 0.0f;

	for (std::vector<BodyEmitter*>::iterator itEmitter = this->emitters.begin();
		itEmitter != this->emitters.end();
		++itEmitter)
	{
		for (std::vector<BodyReceptor*>::iterator itReceptor = this->receptors.begin();
			itReceptor != this->receptors.end();
			++itReceptor)
		{

			tempDistance = calculateDistance((*itEmitter)->GetPosition(), (*itReceptor)->GetPosition());
			if (tempDistance > maxDistance)
				maxDistance = tempDistance;

            if (maxDistance > this->maxWorldDistance)
            {
                this->maxWaveDistance = this->maxWorldDistance;
                return;
            }
		}
	}
	this->maxWaveDistance = maxDistance;
}


void World::checkWaveCreation(BodyEmitter* emitter)
{
	if (emitter->checkForSend(this->currentFrameTime))
	{
		createWave(emitter->GetPosition(), emitter->getId(), emitter->getCurrentSpeed(), emitter->getCurrentAmplitude());
		emitter->setLastSendTime(this->currentFrameTime);
	}
}

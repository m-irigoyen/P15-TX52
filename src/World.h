#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include <iostream>

#include "BodyReceptorComposition.h"
#include "BodyEmitter.h"
#include "Wave.h"
#include <math.h>

#define DEFAULT_PROPAGATION_SPEED 100.0f;

/*
*   The World is the environment. It contains a list of all the PhysicalObjects that exist in it.
*/

enum BODY_TYPE
{
    EMITTER = 0,
    RECEPTOR
};

class World
{
private:
	std::vector<Wave*> waves;	// Change that to a doubly linked list
	std::vector<BodyReceptor*> receptors;
	std::vector<BodyEmitter*> emitters;

    bool optimiseWaveTravelDistance;

	void checkCollisionEvents(Wave* wave, sf::Time elapsedTime);
	void checkWaveCreation(BodyEmitter* emitter);
	bool distanceCheck(float x1, float y1, float x2, float y2, float minDistance, float maxDistance);


	float calculateDistance(float x1, float y1, float x2, float y2);
	float calculateDistance(std::vector<float> pos1, std::vector<float> pos2);
	float calculateDistance(float x1, float y1, std::vector<float> pos2);

	float maxWaveDistance;	// Biggest distance in the world between an emitter and receptor. Passed that distance, all waves are destroyed
	float maxWorldDistance; // If above variable isn't used, this one will be

	sf::Clock* simulationClock;
	sf::Time currentFrameTime;

public:
	World(sf::Clock* clock, float worldLength, float worldHeight);

	void updateMaxWaveDistance();	// Calculates and sets the max wave distance
	bool toggleWaveOptimisation();

	Body* getClosestBodyFromLocation(float x, float y, float rangeTreshold);

    // Creates a body with the given type
	Body* createBody(BODY_TYPE bodyType, float xPos, float yPos);
	// Creates a wave
	Wave* createWave(float x, float y, int emitterId, float speed, float amplitude);
	Wave* createWave(std::vector<float> position, int emitterId, float speed, float amplitude);

	// Update the world
	void update(sf::Time elapsedTime, sf::Time currentFrameTime);

	//Update a receptor in function of its perception
	void setPerception(BodyReceptor* receptor);

	std::vector<Wave*>* getWaves();
	std::vector<BodyEmitter*>* getEmitters();
	std::vector<BodyReceptor*>* getReceptors();

	~World(void);
};

#endif

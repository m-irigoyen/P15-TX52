#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include <iostream>

#include "BodyReceptorComposition.h"
#include "BodyEmitter.h"
#include "Wave.h"
#include <math.h>

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

	void checkCollisionEvents(Wave* wave, sf::Time elapsedTime); 
	bool distanceCheck(float x1, float y1, float x2, float y2, float minDistance, float maxDistance);

	float maxWaveDistance;	// Biggest distance in the world between an emitter and receptor. Passed that distance, all waves are destroyed

	sf::Clock* simulationClock;

public:
	World(sf::Clock* clock);

    // Creates a body with the given type
	Body* createBody(BODY_TYPE bodyType, float xPos, float yPos);
	// Creates a wave 
	Wave* createWave(float x, float y, int emitterId, float speed, float amplitude);

	// Update the world
	void update(sf::Time elapsedTime);

	//Update a receptor in function of its perception
	void updateReceptor(BodyReceptor* receptor);

	std::vector<Wave*>* getWaves();
	std::vector<BodyEmitter*>* getEmitters();
	std::vector<BodyReceptor*>* getReceptors();

	~World(void);
};

#endif

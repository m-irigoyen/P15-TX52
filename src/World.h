#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include <iostream>

#include "BodyReceptor.h"
#include "BodyEmitter.h"
#include "Wave.h"

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
	std::vector<Wave*> waves;
	std::vector<BodyReceptor*> receptors;
	std::vector<BodyEmitter*> emitters;

public:
	World(void);

    // Creates a body with the given type
	Body* createBody(BODY_TYPE bodyType, float xPos, float yPos);
	// Creates a wave 
	Wave* createWave(float x, float y, float radius, float frequency, float speed, float amplitude);

	// Update the world
	void update();

	//Update a receptor in function of its perception
	void updateReceptor(BodyReceptor* receptor);

	std::vector<Wave*>* getWaves();
	std::vector<BodyEmitter*>* getEmitters();
	std::vector<BodyReceptor*>* getReceptors();

	~World(void);
};

#endif

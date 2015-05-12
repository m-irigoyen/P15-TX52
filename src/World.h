#ifndef WORLD_H_
#define WORLD_H_

#include <vector>

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
	std::vector<PhysicalObject*> listOfPhysicalObjects;
	std::vector<Body*> listOfBodys;

public:
	World(void);

    // Creates a body with the given type
	Body* CreateBody(BODY_TYPE bodyType);
	Wave* createWave(int id, float waveLength); //TODO: finish that

	std::vector<PhysicalObject*>* GetListOfPhysicalObjects();
	std::vector<Body*>* GetListOfBodys();

	~World(void);
};

#endif

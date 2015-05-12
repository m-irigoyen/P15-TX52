#ifndef PHYSICALOBJECT_H_
#define PHYSICALOBJECT_H_

#include <vector>

#include "Semantic.h"
#include "World.h"

/*
*   The PhysicalObject is the main class for all the object in the simulation.
*   Everything that exists in the environment is derived from a PhysicalObject.
*   PhysicalObjects are defined by their Semantic.
*/

class PhysicalObject
{
protected:
	Semantic type;
	float posX;
	float posY;

	World* world;

	PhysicalObject(void) {}

public:
	PhysicalObject(Semantic type, World* world);

	virtual void SetPosition(float x, float y);
	virtual void GetPosition(float &x, float &y);
	virtual std::vector<float> GetPosition();

	virtual void SetSemantic(Semantic type);
	virtual Semantic* GetSemantic();

    //TODO: adapt that "dt" with the chrono system from Golé
    // updates the object every frame
	virtual void update(float dt) = 0;

	~PhysicalObject(void);
};

#endif

#ifndef BODY_H_
#define BODY_H_

#include <vector>

#include "PhysicalObject.h"
#include "Perception.h"

/*
*   A Body is a PhysicalObject that can percieve things from the environment, and is linked to an agent.
*   The Agent is the brain, and will give commands to the Body.
*   Here ,the Body can send waves and recieve Perceptions from the environment.
*/

class Body:  public PhysicalObject
{
private:
	Body(void) {}

public:
	Body(Semantic type);

	virtual std::vector<Perception> GetPerception() = 0;    // Returns a list of percieved waves
	virtual void update(float dt) = 0;
    // Position getters and setters
	virtual void SetPosition(float x, float y);
	virtual void GetPosition(float &x, float &y);
	virtual std::vector<float> GetPosition();

    // Semantic getters and setters
	virtual void SetSemantic(Semantic type);
	virtual Semantic* GetSemantic();

	~Body(void);
};

#endif

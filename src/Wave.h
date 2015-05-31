#ifndef WAVE_H_
#define WAVE_H_

#include <iostream>
#include <vector>

#include "PhysicalObject.h"

using namespace std;

class Wave : public PhysicalObject
{
public :
	//Constructor
	Wave(Semantic type, float x, float y, int emitterId, float speed, float amplitude);
	

	//Getter
	float getAmplitude();
	float getSpeed();
	float getRadius();
	int getEmitterId();
	
	void setRadius(float r);

	//Other
	void update(sf::Time elapsedTime);

	// Encountered receptors
	bool hasCollided(int receptorId);
	void onCollisionEvent(int receptorId);

private :
	float m_radius;
	const float m_speed;
	const float m_amplitude;
	const int emitterId;

	std::vector<int> collidedReceptors;
};

#endif
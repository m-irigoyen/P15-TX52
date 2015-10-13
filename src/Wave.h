#ifndef WAVE_H_
#define WAVE_H_

#include <iostream>
#include <vector>

#include "PhysicalObject.h"

#define COEFF_ATTENUATION 1

using namespace std;

class Wave : public PhysicalObject
{
public :
	//Constructor
	Wave(Semantic type, float x, float y, int emitterId, float speed, float amplitude, float ampLossPerSec = 50.0f);
	

	//Getter
	float getAmplitude();
	float getAmplitudeLossPerSecond();
	float getSpeed();
	float getRadius();
	int getEmitterId();
	
	void setRadius(float r);

	//Other
	void update(sf::Time elapsedTime);
	bool attenuate(sf::Time elapsedTime);	// Returns true if wave is to be destroyed

	// Encountered receptors
	bool hasCollided(int receptorId);
	void onCollisionEvent(int receptorId);

private :
	float m_radius;
	const float m_speed;
	float m_amplitude;
	const int emitterId;

	float amplitudeLossPerSecond;

	std::vector<int> collidedReceptors;
};

#endif
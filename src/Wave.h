#ifndef WAVE_H_
#define WAVE_H_

#include <iostream>
#include <vector>

#include "PhysicalObject.h"
#include "History.h"

using namespace std;

class Wave : public PhysicalObject
{
public :
	//Constructor
	Wave(Semantic type);
	//Init
	void initWave(float x, float y, float r, float f, float s, float a);
	//Getter
	float getRadius();
	float getFrequency();
	float getSpeed();
	float getAmplitude();
	vector<History> getHistory();
	//Setter
	void setRadius(float r);
	void setFrequency(float f);
	void setSpeed(float s);
	void setAmplitude(float a);
	void setNewFrequency(float f, int t);

private :
	float m_radius;
	float m_frequency;
	float m_speed;
	float m_amplitude;
	vector<History> m_histories;
};

#endif
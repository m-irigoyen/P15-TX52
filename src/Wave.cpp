#include "Wave.h"

//Constructor

Wave::Wave(Semantic type) : PhysicalObject(type)
{
	
}

//Init
void Wave::initWave(float x, float y, float r, float f, float s, float a)
{
	SetPosition(x, y);
	setRadius(r);
	setFrequency(f);
	setSpeed(s);
	setAmplitude(a);
}

//Getter
float Wave::getRadius()
{
	return m_radius;
}

float Wave::getFrequency()
{
	return m_frequency;
}

float Wave::getSpeed()
{
	return m_speed;
}

float Wave::getAmplitude()
{
	return m_amplitude;
}

vector<History> Wave::getHistory()
{
	return m_histories;
}

//Setter
void Wave::setRadius(float r)
{
	m_radius = r;
}

void Wave::setFrequency(float f)
{
	m_frequency = f;
}

void Wave::setSpeed(float s)
{
	m_speed = s;
}

void Wave::setAmplitude(float a)
{
	m_amplitude = a;
}

void Wave::setNewFrequency(float f, int t)
{
	m_histories.push_back(new History(f, t));
}
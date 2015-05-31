#include "Receptor.h"

void Receptor::onWaveCollision(int emitterId, sf::Time contact, float amplitude)
{
	this->perception.addNewWave(emitterId, contact, amplitude);
}

float Receptor::calculateValueAtT(sf::Time t)
{
	return 0.0f;
}

/*!
Precision = how many points to compute
*/
std::vector<float> Receptor::computePercievedWave(sf::Time start, sf::Time duration, int precision)
{
	std::vector<float> test;
	return test;
}
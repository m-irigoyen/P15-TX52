#include "BodyReceptorComposition.h"


BodyReceptorComposition::BodyReceptorComposition(Semantic type, float x, float y) : BodyReceptor(type, x, y)
{

}

	//Receptor functions

// Initialises the receptor
void BodyReceptorComposition::initialise()
{

}

// Returns what the receptor can make of all it has recieved. #PHYSICS STUFF
WAVE_COMPOSITION BodyReceptorComposition::getPerception()
{
	// TODO: Make the algorithm a hell of a lot better than that

	for (std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator it = this->perception.getWaves()->begin();
		it != this->perception.getWaves()->end();
		++it)
	{
		if (it->second.second.first != -1.0f)	// Frequency isn't null : we can update that wave
		{
			this->currentPerception.frequency = it->second.second.first;
			this->currentPerception.amplitude = it->second.second.second;
		}
	}
	return this->currentPerception;
}

float BodyReceptorComposition::calculateValueAtT(sf::Time t)
{
	float result = 0.0f;
	for (std::map<int, std::pair<sf::Time, std::pair<float, float>>>::iterator it = this->perception.getWaves()->begin();
		it != this->perception.getWaves()->end();
		++it)
	{
		result += calculateValueAtT(t, it->second.first, it->second.second.first, it->second.second.second);
	}

	return result;
}

// Calculates value for given wave at given time
float BodyReceptorComposition::calculateValueAtT(sf::Time t, sf::Time firstContact, float frequency, float amplitude)
{
	//TODO: Do the math
	return 0.0f;
}

	//! Precision = how many points to compute
std::vector<float> BodyReceptorComposition::computePercievedWave(sf::Time start, sf::Time duration, int precision)
{
	std::vector<float> test;
	return test;
}

void BodyReceptorComposition::updateComputedValues(sf::Time currentTime)
{
    this->computedValues.insert(std::pair<sf::Time, float>(currentTime, calculateValueAtT(currentTime)));
}

//Body functions
void BodyReceptorComposition::update(sf::Time elapsedTime)
{

}
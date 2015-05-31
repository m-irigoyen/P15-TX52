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
	// Make the algorithm a hell of a lot better than that

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

//Body functions
void BodyReceptorComposition::update(sf::Time elapsedTime)
{

}
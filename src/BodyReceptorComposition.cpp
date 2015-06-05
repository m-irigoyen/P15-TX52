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
    sf::Time elapsedTime = t - firstContact;
    float period = 2*M_PI*frequency;
    while (elapsedTime.asSeconds() > period)
    {
        elapsedTime = sf::seconds(elapsedTime.asSeconds() - period);
    }
	return amplitude*sin(elapsedTime.asSeconds()/frequency);
}

void BodyReceptorComposition::updateComputedValues(sf::Time currentTime)
{
    this->computedValues.push_front(std::pair<sf::Time, float>(currentTime, calculateValueAtT(currentTime)));
    sf::Time differenceTime = currentTime - this->computedValues.back().first;
    //std::cout << "differenceTime " << differenceTime.asSeconds() << std::endl;
    //std::cout << "memoryTime " << differenceTime.asSeconds() << std::endl;
    while(!this->computedValues.empty() && (currentTime - this->computedValues.back().first) > this->memoryTime)
    {
        std::cout << "OUAIS SALUT OUAIS " << std::endl;
        this->computedValues.pop_back();
    }
}

//Body functions
void BodyReceptorComposition::update(sf::Time elapsedTime)
{

}

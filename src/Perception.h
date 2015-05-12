#ifndef PERCEPTION_H_
#define PERCEPTION_H_

/*
*   A Perception object is constructed by the environment to represent all the wavelengths that a Body percieves.
*   For each wave percieved by a body, there will be one Perception object
*/

class Perception
{
private:
	Perception(void) {}
	int m_waveId;   // The id of the wave percieved. (The id depends of the emitter)
	float m_waveLength; // The wavelength percieved

public:
	Perception(int waveId, float waveLength);

    int getWaveId();    // Gets the id of the wave percieved
    float getWaveLength();  // Gets the lenght of the wave percieved
};

#endif

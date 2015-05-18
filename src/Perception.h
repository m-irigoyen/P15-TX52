#ifndef PERCEPTION_H_
#define PERCEPTION_H_

/*
*   A Perception object is constructed by the environment to represent all the wavelengths that a Body percieves.
*   For each wave percieved by a body, there will be one Perception object
*/

class Perception
{
private:
	int m_waveId;   // The id of the wave percieved. (The id depends of the emitter)
	float m_frequency; // The wavelength percieved

public:
    Perception();
	Perception(int waveId, float frequency);

    int getWaveId();    // Gets the id of the wave percieved
    void setWaveId(int waveId);
    float getFrequency();  // Gets the lenght of the wave percieved
    void setFrequency(float frequency);
};

#endif

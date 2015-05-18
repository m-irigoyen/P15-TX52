#include "Perception.h"

Perception::Perception() : m_waveId(0), m_frequency(0.0f)
{

}

Perception::Perception(int waveId, float frequency) : m_waveId(waveId), m_frequency(frequency)
{

}

void Perception::setWaveId(int waveId)
{
    m_waveId = waveId;
}

int Perception::getWaveId()
{
    return m_waveId;
}

float Perception::getFrequency()
{
    return m_frequency;
}

void Perception::setFrequency(float frequency)
{
    m_frequency = frequency;
}

#include "Perception.h"

Perception::Perception(int waveId, float waveLength) : m_waveId(waveId), m_waveLength(waveLength)
{

}

int Perception::getWaveId()
{
    return m_waveId;
}

float Perception::getWaveLength()
{
    return m_waveLength;
}

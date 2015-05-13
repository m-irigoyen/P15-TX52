#include "History.h"


//Constructor
History::History()
{

}

History::History(float f, int t)
{
	addValue(f, t);
}

//Destructor
History::~History()
{
	m_frequency.clear();	
	m_time.clear();

}
//Getter
vector<float> History::getFrequency()
{
	return m_frequency;
}

vector<int> History::getTime()
{
	return m_time;
}

float History::getFrequencyInTime(int time)
{
	int i;
	for (i = 0; i < m_frequency.size(); ++i)
	{
		if (time < m_time.at(i))
		{
			return m_frequency.at(i - 1);
		}
	}
}

//Setter
void History::addValue(float f, int t)
{
	m_frequency.push_back(f);
	m_time.push_back(t);
}

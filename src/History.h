#pragma once
#include <vector>

using namespace std;

class History
{
public:
	//Constructor
	History();
	History(float f, int t);
	//Destructor
	~History();
	//Getter
	vector<float> getFrequency();
	vector<int> getTime();
	float getFrequencyInTime(int time);
	//Setter
	void addValue(float f, int t);

private :
	vector<float> m_frequency;
	vector<int> m_time;
};


#include "Simulator.h"


Simulator::Simulator()
{
	this->SFMLView.Init(800, 800);
}

void Simulator::addAgent(Agent* agent, BODY_TYPE bodyType, float xPos, float yPos)
{
    this->world.
}

void Simulator::Run()
{
	std::chrono::system_clock::time_point start_time, end_time;
	int eventID = 0;

	while(eventID != 1)
	{
		start_time = std::chrono::high_resolution_clock::now();

		eventID = this->SFMLView.CheckEvent();

		int nbAgents = static_cast<int>(agents.size());
		for (int i = 0; i < nbAgents; ++i)
		{
			this->agents[i].Life();
		}

		this->SFMLView.Draw();

		end_time = std::chrono::high_resolution_clock::now();
		std::cout <<"frame time : "<< std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << std::endl;
	}
}

Simulator::~Simulator(void)
{
}

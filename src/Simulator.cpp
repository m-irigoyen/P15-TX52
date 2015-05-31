#include "Simulator.h"


Simulator::Simulator() : finishSimulation(false), frameFlag(true)
{
	this->SFMLView.Init(800, 800);

	this->SFMLView.SetWorld(&this->world);

    // FIXME: this is test code, remove it later
	addAgent(new AgentReceptor(this->problem), BODY_TYPE::RECEPTOR, 200,200);
	addAgent(new AgentEmitter(this->problem), BODY_TYPE::EMITTER, 500,200);
}

void Simulator::addAgent(Agent* agent, BODY_TYPE bodyType, float xPos, float yPos)
{
	Body* body = this->world.createBody(bodyType, xPos, yPos);
	agent->connect(body);
	this->agents.push_back(agent);
}

void Simulator::run(sf::Time refreshRate)
{
	simulationClock.restart();

	int eventID = 0;

	sf::Time startTime, endTime;

	// VI51 VERSION
	std::cout << "Starting program loop" << std::endl;
	while (!finishSimulation)
	{
		if (this->frameFlag)
		{
			this->frameFlag = false;
			startTime = simulationClock.getElapsedTime(); 
			std::cout << endl << "Simulator::Run : STARTING FRAME" << endl;

			// UPDATE STUFF
			this->world.update(refreshRate);

			// Updating agents
			int nbAgents = static_cast<int>(agents.size());
			for (int i = 0; i < nbAgents; ++i)
				agents[i]->live();

			// Drawing
			this->SFMLView.Draw();

			// Ending the frame
			endTime = simulationClock.getElapsedTime();
			sf::Time frameTime = endTime - startTime;

			std::cout << "frame time : " << frameTime.asMilliseconds() << " ms, waiting " << refreshRate.asMilliseconds() - frameTime.asMilliseconds() << " ms" << std::endl;

			std::cout << "Simulator::Run : FRAME ENDED" << endl;
		}
		else
		{
			checkEvents();	// Checking for user input

			endTime = simulationClock.getElapsedTime();
			sf::Time frameTime = endTime - startTime;

			if (frameTime > refreshRate)
				frameFlag = true;
		}
	}
}

Simulator::~Simulator(void)
{
}

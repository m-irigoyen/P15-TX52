#include "Simulator.h"


Simulator::Simulator() : world(&simulationClock, 800, 800), finishSimulation(false), frameFlag(true), problem(NULL), selectedBody(NULL)
{
	this->SFMLView.Init(800, 800);

	this->SFMLView.SetWorld(&this->world);
	this->window = this->SFMLView.getWindow();

	init();
}

void Simulator::init()
{
	addAgent(new AgentReceptor(this->problem), BODY_TYPE::RECEPTOR, 200, 200);
	addAgent(new AgentReceptor(this->problem), BODY_TYPE::RECEPTOR, 300, 200);
	addAgent(new AgentReceptor(this->problem), BODY_TYPE::RECEPTOR, 400, 200);

	addAgent(new AgentEmitter(this->problem), BODY_TYPE::EMITTER, 500, 200);
	addAgent(new AgentEmitter(this->problem), BODY_TYPE::EMITTER, 500, 300);
	addAgent(new AgentEmitter(this->problem), BODY_TYPE::EMITTER, 500, 400);
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
			//std::cout << endl << "Simulator::Run : STARTING FRAME" << endl;

			// UPDATE STUFF
			this->world.update(refreshRate, startTime);

			// Updating agents
			int nbAgents = static_cast<int>(agents.size());
			for (int i = 0; i < nbAgents; ++i)
				agents[i]->live();

			// Drawing
			this->SFMLView.Draw();

			// Ending the frame
			endTime = simulationClock.getElapsedTime();
			sf::Time frameTime = endTime - startTime;

			/*if (frameTime.asMilliseconds() > 17)
				std::cout << "frame time : " << frameTime.asMilliseconds() << " ms, threshold was " << 1/30 << "ms" << std::endl;*/

			//std::cout << "frame time : " << frameTime.asMilliseconds() << " ms, waiting " << refreshRate.asMilliseconds() - frameTime.asMilliseconds() << " ms" << std::endl;

			//std::cout << "Simulator::Run : FRAME ENDED" << endl;
		}
		else
		{
			checkEvents();	// Checking for user input

			//std::cout << "C'est là?" << std::endl;

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

// Check simulation events
void Simulator::checkEvents()
{
	// Checking for window events
	sf::Event event;
	while (this->window->pollEvent(event))
	{
        switch (event.type)
        {
                case sf::Event::Closed :
                    this->window->close();
                    finishSimulation = true;
                    break;
                case sf::Event::KeyPressed :
                    if (event.key.code == sf::Keyboard::O)
                    {
                        if (this->world.toggleWaveOptimisation())
                            std::cout << "Wave optimisation : on" << std::endl;
                        else
                            std::cout << "Wave optimisation : off" << std::endl;
                    }
                    break;
                case sf::Event::MouseButtonPressed :
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        //std::cout << "Searching body in " <<
                        selectedBody = this->world.getClosestBodyFromLocation(
                            event.mouseButton.x,event.mouseButton.y,2*EMITTER_RADIUSSIZE);
                    }

                    break;
                case sf::Event::MouseMoved :
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && selectedBody != NULL)
                    {
                        selectedBody->SetPosition(event.mouseMove.x, event.mouseMove.y);
                        //std::cout << "MOVING BODY TO " << event.mouseMove.x << "," << event.mouseMove.y <<  std::endl;
                    }
                    this->world.updateMaxWaveDistance();    // Recalculating max wave distance
                    break;
        }
	}
}

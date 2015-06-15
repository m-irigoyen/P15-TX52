#include "Simulator.h"


Simulator::Simulator() : world(&simulationClock, 800, 800), finishSimulation(false), frameFlag(true), problem(NULL), selectedBody(NULL)
{
	this->problem = new ProblemPointer(400, 400);

	this->SFMLView.Init(400, 400);

	this->SFMLView.SetWorld(&this->world);
	this->window = this->SFMLView.getWindow();

	init();
}

void Simulator::init()
{
	std::cout << "Initialising" << std::endl;
	this->problem = new ProblemPointer(500, 500);
	
	addEmitter(200,200);
	addReceptor(400, 200);
	std::cout << "Init done" << std::endl;
}

void Simulator::addEmitter(float xPos, float yPos)
{
	BodyEmitter* body = static_cast<BodyEmitter*>(this->world.createBody(BODY_TYPE::EMITTER, xPos, yPos));
	if (body != NULL)
	{
		ProblemPointer* castedProblem = static_cast<ProblemPointer*>(this->problem);
		if (castedProblem != NULL)
		{
			AgentEmitterProblemPointer* agent = new AgentEmitterProblemPointer(castedProblem);
			agent->connectCasted(body);
			this->agents.push_back(agent);
		}
		else
			std::cout << "ERROR : couldn't cast problem to ProblemPointer" << std::endl;
	}
	else
		std::cout << "ERROR : couldn't cast resulting body" << std::endl;
}

void Simulator::addReceptor(float xPos, float yPos)
{
	BodyReceptorComposition* body = static_cast<BodyReceptorComposition*>(this->world.createBody(BODY_TYPE::RECEPTOR, xPos, yPos));
	if (body != NULL)
	{
		ProblemPointer* castedProblem = static_cast<ProblemPointer*>(this->problem);
		if (castedProblem != NULL)
		{
			AgentReceptorProblemPointer* agent = new AgentReceptorProblemPointer(castedProblem);
			agent->connectCasted(body);
			this->agents.push_back(agent);
		}
		else
			std::cout << "ERROR : couldn't cast problem to ProblemPointer" << std::endl;
	}
	else
		std::cout << "ERROR : couldn't cast resulting body" << std::endl;
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
			// updating problem
			this->problem->run(refreshRate);

			this->world.update(refreshRate, startTime);

			// Updating agents
			for (std::vector<Agent*>::iterator it = this->agents.begin(); it != this->agents.end(); ++it)
			{
				(*it)->live();
			}

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
	for (std::vector<Agent*>::iterator it = this->agents.begin(); it != this->agents.end(); ++it)
	{
		delete (*it);
		*it = NULL;
	}
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
					switch (event.key.code)
					{
					case sf::Keyboard::Escape :
						this->window->close();
						this->finishSimulation = true;
						break;
					}
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

#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <vector>
#include <chrono>
#include <iostream>

#include "AgentEmitter.h"
#include "AgentReceptor.h"
#include "GraphicView.h"

/*
*   The Simulator is the main class of the project.
*   The Simulator is created with an instance of the Problem class. The Problem modelises what it is that the Simulator is trying
*   to solve : drone, pendulum, slink, etc.
*   The Simulator then inits the program, creates the world and the agents, links the agents to their bodies, links the agents
*   to the Problem accordingly.
*
*   It then runs the whole thing via the Run function.
*/


class Simulator
{
private:
	GraphicView SFMLView;
	World world;    // The environment
	std::vector<Agent*> agents; // All the agents
    Problem* problem;   // The instance of the Problem.
	sf::RenderWindow* window;

	sf::Clock simulationClock;
	bool finishSimulation;
	bool frameFlag;

public:
	Simulator();
	void init();	

    // Creates a body for the given agent at given position, then adds this agent to the list,
    void addAgent(Agent* agent, BODY_TYPE bodyType, float xPos, float yPos);

	void checkEvents();	// Check simulation events
	void run(sf::Time refreshRate);

	~Simulator(void);
};

#endif

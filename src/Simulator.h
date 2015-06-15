#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <vector>
#include <chrono>
#include <iostream>

#include "GraphicView.h"

// Pointer problem
#include "ProblemPointer.h"
#include "AgentEmitterProblemPointer.h"
#include "AgentReceptorProblemPointer.h"


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
	sf::RenderWindow* window;
	
	World world;    // The environment
	std::vector<Agent*> agents; // All the agents
    
	

	sf::Clock simulationClock;
	bool finishSimulation;
	bool frameFlag;

	//User interface stuff
	Body* selectedBody;

	// ProblemPointer
	ProblemPointer* problem;   // The instance of the Problem.
	sf::CircleShape secondPointer;

public:
	Simulator();
	void init();

    // Creates a body for the given agent at given position, then adds this agent to the list,
	void addEmitter(float xPos, float yPos);
	void addReceptor(float xPos, float yPos);

	void checkEvents();	// Check simulation events
	void run(sf::Time refreshRate);

	~Simulator(void);
};

#endif

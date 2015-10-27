#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>

/*
* The Problem class creates and run the problem to be solved. (pendulum, drone, etc)
*/

enum PROBLEM_TYPE
{
	POINTER,
	DRONE,
	ROCKET
};

class Problem
{
public:
	virtual void run(sf::Time elapsedTime) = 0;			// Run the problem
	virtual void draw(sf::RenderWindow* window) = 0;	// Draw the problem on the given window
};

#endif

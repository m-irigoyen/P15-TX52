#ifndef PROBLEM_H_
#define PROBLEM_H_

/*
* The Problem class creates and run the problem to be solved. (pendulum, drone, etc)
*/

class Problem
{
public:
	virtual void run(sf::Time elapsedTime) = 0;
};

#endif

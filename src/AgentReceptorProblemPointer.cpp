#include "AgentReceptorProblemPointer.h"

AgentReceptorProblemPointer::AgentReceptorProblemPointer(ProblemPointer* problem, BodyReceptorComposition* body) : AgentReceptor(problem, body), castedProblem(problem)
{

}

void AgentReceptorProblemPointer::live()
{
	if (!this->isLinked())
	{
		std::cout << "ERROR : AgentReceptorProblemPointer::live : agent isn't linked to a body" << std::endl;
		return;
	}
	else if (!this->isProblemLinked())
	{
		std::cout << "ERROR : AgentReceptorProblemPointer::live : agent isn't linked to a problem" << std::endl;
		return;
	}

	WAVE_COMPOSITION perception = this->castedBody->getPerception();

	float mouseX, mouseY;
	int windowWidth, windowHeight;

	this->castedProblem->getWindowDimensions(windowWidth, windowHeight);

	// Decoding x/y position
	perception.frequency += 2;
	mouseX = (perception.frequency * windowWidth) / 5;

	perception.amplitude += 1;
	mouseY = (perception.amplitude * windowHeight) / 10;

	this->castedProblem->setSecondPointerPosition(mouseX, mouseY);
	//std::cout << "Setting second pointer position at : " << mouseX << "," << mouseY << std::endl;
}

bool AgentReceptorProblemPointer::isLinked()
{
	if (Agent::isLinked() && this->castedBody != NULL)
		return true;
	return false;
}

bool AgentReceptorProblemPointer::isProblemLinked()
{
	if (Agent::isProblemLinked() && this->castedProblem != NULL)
	{
		return true;
	}
	return false;
}
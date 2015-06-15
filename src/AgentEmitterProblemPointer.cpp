#include "AgentEmitterProblemPointer.h"

AgentEmitterProblemPointer::AgentEmitterProblemPointer(ProblemPointer* problem, BodyEmitter* body) : AgentEmitter(problem, body), castedProblem(problem)
{

}

void AgentEmitterProblemPointer::live()
{
	if (!this->isLinked())
	{
		std::cout << "ERROR : AgentEmitterProblemPointer::live : agent isn't linked to a body" << std::endl;
		return;
	}
	else if (!this->isProblemLinked())
	{
		std::cout << "ERROR : AgentEmitterProblemPointer::live : agent isn't linked to a problem" << std::endl;
		return;
	}

	/*float mouseX, mouseY;
	int windowWidth, windowHeight;
	
	this->castedProblem->getMousePointerPosition(mouseX, mouseY);
	this->castedProblem->getWindowDimensions(windowWidth, windowHeight);

	// Encoding x/y position
	float frequency = ((mouseX * 5) / (float)windowWidth) + 2;	// offsetting a bit, to make sure wave transmission is kept
	float amplitude = ((mouseX * 10) / (float)windowWidth) + 1;

	this->castedBody->send(frequency, amplitude);
	std::cout << "Emitting : " << frequency << ", " << amplitude << std::endl;;*/
	this->castedBody->send(2.0f, 1.0f);
}

// Checks if agent is linked to a body
bool AgentEmitterProblemPointer::isProblemLinked()
{
	if (Agent::isProblemLinked() && this->castedProblem != NULL)
		return true;
	return false;

}

bool AgentEmitterProblemPointer::isLinked()
{
	if (Agent::isLinked() && this->castedBody != NULL)
		return true;
	return false;
}

AgentEmitterProblemPointer::~AgentEmitterProblemPointer(void)
{

}
#include "ProblemPointer.h"

ProblemPointer::ProblemPointer(int width, int height, sf::CircleShape& secondPointer) : secondPointer(secondPointer), windowWidth(width), windowHeight(height)
{
	this->secondPointer.setFillColor(sf::Color::Red);
	this->secondPointer.setPosition(0.0f, 0.0f);
}

void ProblemPointer::run(sf::Time elapsedTime)
{
	
}

void ProblemPointer::setSecondPointerPosition(float x, float y)
{
	this->secondPointer.setPosition(x, y);
}

void ProblemPointer::getMousePointerPosition(float& x, float& y)
{
	x = this->currentMouseX;
	y = this->currentMouseY;
}

void ProblemPointer::getSecondPointerPosition(float& x, float& y)
{
	x = this->secondPointer.getPosition().x;
	y = this->secondPointer.getPosition().y;
}

void ProblemPointer::setCurrentMouse(float x, float y)
{
	this->currentMouseX = x;
	this->currentMouseY= y;
}

void ProblemPointer::getWindowDimensions(int& width, int& height)
{
	width = this->windowWidth;
	height = this->windowHeight;
}
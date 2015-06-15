#include "ProblemPointer.h"

ProblemPointer::ProblemPointer(int width, int height, sf::CircleShape& secondPointer) : secondPointer(secondPointer), windowWidth(width), windowHeight(height)
{
	this->secondPointer.setFillColor(sf::Color::Red);
	this->secondPointer.setPosition(0.0f, 0.0f);
}

void ProblemPointer::run(sf::Time elapsedTime)
{
	sf::Event event;
	while (this->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::MouseMoved:
			
			this->currentMouseX = event.mouseMove.x;
			this->currentMouseY = event.mouseMove.y;
			//std::cout << "New mouse pos : " << this->currentMouseX << "," << this->currentMouseY << std::endl;
			break;
		case sf::Event::MouseButtonPressed:
			this->setSecondPointerPosition(this->windowWidth / 2, this->windowHeight / 2);
			break;
		case sf::Event::Closed :
			this->window.close();
		}
	}
		this->window.clear(sf::Color::Black);
		this->window.draw(this->secondPointer);
		this->window.display();
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

void ProblemPointer::getWindowDimensions(int& width, int& height)
{
	width = this->windowWidth;
	height = this->windowHeight;
}
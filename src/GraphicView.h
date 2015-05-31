#ifndef GRAPHICVIEW_H_
#define GRAPHICVIEW_H_

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "World.h"

#define RECEPTOR_SIZE 5
#define EMITTER_SIZE 5
#define WAVE_SIZE 2

/*
*   The GraphicView is charged of visualizing the whole thing.
*/

class GraphicView
{
private:
	sf::RenderWindow* window;
	World* world;
	std::vector<sf::CircleShape> receptors;
	std::vector<sf::CircleShape> emitters;
	std::vector<sf::CircleShape> waves;
public:
	GraphicView(void);

	void Init(int height, int width);
	int CheckEvent();
	void Draw();

	sf::RenderWindow* getWindow();

	void SetWorld(World* world);

	~GraphicView(void);
};

#endif

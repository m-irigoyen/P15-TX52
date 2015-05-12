#ifndef GRAPHICVIEW_H_
#define GRAPHICVIEW_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "World.h"

/*
*   The GraphicView is charged of visualizing the whole thing.
*/

class GraphicView
{
private:
	sf::RenderWindow* window;
	World* world;
	std::vector<sf::CircleShape> bodyShape;

public:
	GraphicView(void);

	void Init(int height, int width);
	int CheckEvent();
	void Draw();

	void SetWorld(World* world);

	~GraphicView(void);
};

#endif

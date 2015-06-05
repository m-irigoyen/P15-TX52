#ifndef GRAPHICVIEW_H_
#define GRAPHICVIEW_H_

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "World.h"

#define RECEPTOR_RADIUSSIZE 6
#define EMITTER_RADIUSSIZE 6
#define WAVE_SIZE 2

//#define SKIP_WAVES
//#define SKIP_EMITTERS
//#define SKIP_RECEPTORS

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

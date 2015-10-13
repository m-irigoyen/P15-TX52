#ifndef GRAPHICVIEW_H_
#define GRAPHICVIEW_H_

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "World.h"

#define RECEPTOR_RADIUSSIZE 6
#define EMITTER_RADIUSSIZE 6
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

	// display stuff
	bool displayWaves;
	bool displayReceptors;
	bool displayEmitters;

	// Used to compute the alpha component of waves
	float maxAmplitude;

public:
	GraphicView();

	void Init(int height, int width);
	int CheckEvent();
	void Draw();

	void setDisplayWaves(bool displayWaves);
	void setDisplayEmitters(bool displayEmitters);
	void setDisplayReceptors(bool displayReceptors);
	void setMaxAmplitude(float amplitude);
	void toggleDisplayWaves();

	sf::RenderWindow* getWindow();

	void SetWorld(World* world);

	~GraphicView(void);
};

#endif

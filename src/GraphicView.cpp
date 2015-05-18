#include "GraphicView.h"


GraphicView::GraphicView(void)
{
}

void GraphicView::Init(int height, int width)
{
	this->window = new sf::RenderWindow(sf::VideoMode(height, width), "TX52 - Wave Simulator");
	this->window->setVerticalSyncEnabled(true);
}

int GraphicView::CheckEvent()
{
	sf::Event event;
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
		{
            this->window->close();
			return 1;
		}
    }
	return 0;
}

void GraphicView::Draw()
{
	window->clear(sf::Color::Black);

    //Receptors
	std::vector<BodyReceptor*>* worldReceptors = this->world->getReceptors();
	if (this->receptors.size() != worldReceptors->size())
	{
		this->receptors.clear();
		for (int i=0; i < worldReceptors->size(); ++i)
		{
			this->receptors.push_back(sf::CircleShape(2));
			this->receptors.at(this->receptors.size()-1).setFillColor(sf::Color(255, 0, 0));
		}
	}

	for (int idCurrentBody=0; idCurrentBody < worldReceptors->size(); ++idCurrentBody)
	{
		std::vector<float> pos = worldReceptors->at(idCurrentBody)->GetPosition();
		this->receptors[idCurrentBody].setPosition(pos[0], pos[1]);
		window->draw(this->receptors[idCurrentBody]);
	}

    //Emitters
	std::vector<BodyEmitter*>* worldEmitters = this->world->getEmitters();
	if (this->emitters.size() != worldEmitters->size())
	{
		this->emitters.clear();
		for (int i=0; i < worldEmitters->size(); ++i)
		{
			this->emitters.push_back(sf::CircleShape(2));
			this->emitters.at(this->emitters.size()-1).setFillColor(sf::Color(0, 255, 0));
		}
	}

	for (int idCurrentBody=0; idCurrentBody < worldEmitters->size(); ++idCurrentBody)
	{
		std::vector<float> pos = worldEmitters->at(idCurrentBody)->GetPosition();
		this->emitters[idCurrentBody].setPosition(pos[0], pos[1]);
		window->draw(this->emitters[idCurrentBody]);
	}

	window->display();
}

void GraphicView::SetWorld(World* world)
{
	this->world = world;
}

GraphicView::~GraphicView(void)
{
	this->window->clear();
	delete this->window;
}

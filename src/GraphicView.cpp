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

	
#ifndef SKIP_RECEPTORS
    //Receptors
	std::vector<BodyReceptor*>* worldReceptors = this->world->getReceptors();
	if (this->receptors.size() != worldReceptors->size())
	{
		this->receptors.clear();
		for (int i=0; i < worldReceptors->size(); ++i)
		{
			this->receptors.push_back(sf::CircleShape(RECEPTOR_SIZE));
			this->receptors.at(this->receptors.size()-1).setFillColor(sf::Color(255, 0, 0));
			this->receptors.at(this->receptors.size() - 1).setOrigin(RECEPTOR_SIZE , RECEPTOR_SIZE );
		}
	}

	for (int idCurrentBody=0; idCurrentBody < worldReceptors->size(); ++idCurrentBody)
	{
		std::vector<float> pos = worldReceptors->at(idCurrentBody)->GetPosition();
		this->receptors[idCurrentBody].setPosition(pos[0], pos[1]);
		window->draw(this->receptors[idCurrentBody]);
	}

	/*std::cout << "Receptor size : " << this->receptors.size() << std::endl;
	std::cout << "World Receptor size : " << worldReceptors->size() << std::endl;*/
#endif

#ifndef SKIP_EMITTERS
    //Emitters
	std::vector<BodyEmitter*>* worldEmitters = this->world->getEmitters();
	if (this->emitters.size() != worldEmitters->size())
	{
		this->emitters.clear();
		for (int i=0; i < worldEmitters->size(); ++i)
		{
			this->emitters.push_back(sf::CircleShape(EMITTER_SIZE));
			this->emitters.at(this->emitters.size()-1).setFillColor(sf::Color(0, 255, 0));
			this->emitters.at(this->emitters.size() - 1).setOrigin(EMITTER_SIZE , EMITTER_SIZE );
		}
	}

	for (int idCurrentBody=0; idCurrentBody < worldEmitters->size(); ++idCurrentBody)
	{
		std::vector<float> pos = worldEmitters->at(idCurrentBody)->GetPosition();
		this->emitters[idCurrentBody].setPosition(pos[0], pos[1]);
		window->draw(this->emitters[idCurrentBody]);
	}

	/*std::cout << "Emitter size : " << this->emitters.size() << std::endl;
	std::cout << "World Emitter size : " << worldEmitters->size() << std::endl;*/
#endif

#ifndef SKIP_WAVES
	//Waves
	std::vector<Wave*>* worldWaves = this->world->getWaves();
	if (this->waves.size() != worldWaves->size())
	{
		this->waves.clear();
		for (int i = 0; i < worldWaves->size(); ++i)
		{
			//this->waves.push_back(sf::CircleShape(WAVE_SIZE));
			
			sf::CircleShape newWave(0.0f);
			// Setting color
			newWave.setFillColor(sf::Color(255, 255, 255,0));
			newWave.setOutlineColor(sf::Color(0, 0, 255,255));
			newWave.setOutlineThickness(1);

			// Setting origin
			float x;
			float y;
			worldWaves->at(i)->GetPosition(x, y);
			newWave.setPosition(x, y);
//			std::cout << "New wave origin : " << x << "," << y << endl;
			
			
			/*this->waves.at(this->waves.size() - 1).setFillColor(sf::Color(255, 255, 255, 1));
			this->waves.at(this->waves.size() - 1).setOutlineColor(sf::Color(0, 0, 255));*/

			this->waves.push_back(newWave);
		}
	}

	int cpt = 0;
	for (int idCurrentWave = 0; idCurrentWave < worldWaves->size(); ++idCurrentWave)
	{
		this->waves[idCurrentWave].setOrigin(worldWaves->at(idCurrentWave)->getRadius(), worldWaves->at(idCurrentWave)->getRadius());
		this->waves[idCurrentWave].setRadius(worldWaves->at(idCurrentWave)->getRadius());
		window->draw(this->waves[idCurrentWave]);

		/*std::cout << "Drawing a wave at " << this->waves[idCurrentWave].getPosition().x << "," << this->waves[idCurrentWave].getPosition().y <<
			", radius : " << this->waves[idCurrentWave].getRadius() << std::endl;*/
		++cpt;
	}

	/*std::cout << "Wave size : " << this->waves.size() << std::endl;
	std::cout << "World Wave size : " << worldWaves->size() << std::endl;*/
#endif

	window->display();
}

void GraphicView::SetWorld(World* world)
{
	this->world = world;
}

sf::RenderWindow* GraphicView::getWindow()
{
	return this->window;
}

GraphicView::~GraphicView(void)
{
	this->window->clear();
	delete this->window;
}

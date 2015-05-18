#include "Simulator.h"


Simulator::Simulator()
{
	this->SFMLView.Init(800, 800);

	this->SFMLView.SetWorld(&this->world);

    // FIXME: this is test code, remove it later
	addAgent(new AgentReceptor(this->problem), BODY_TYPE::RECEPTOR, 200,200);
	addAgent(new AgentEmitter(this->problem), BODY_TYPE::EMITTER, 500,200);
}

void Simulator::addAgent(Agent* agent, BODY_TYPE bodyType, float xPos, float yPos)
{
	Body* body = this->world.createBody(bodyType, xPos, yPos);
	agent->connect(body);
	this->agents.push_back(agent);
}

void Simulator::run(int elapsedTime)
{
	std::chrono::system_clock::time_point start_time, end_time;
	int eventID = 0;

	while(eventID != 1)
	{
		start_time = std::chrono::high_resolution_clock::now();

		//Updating physical objects
		for (std::vector<PhysicalObject*>::iterator it = this->world.GetListOfPhysicalObjects()->begin();
			it != this->world.GetListOfPhysicalObjects()->end();
			++it)
		{
			(*it)->update(elapsedTime);
		}

		// Updating Bodies
		for (std::vector<BodyEmitter*>::iterator it = this->world.getEmitters()->begin();
			it != this->world.getEmitters()->end();
			++it)
		{
			(*it)->update(elapsedTime);
		}

		for (std::vector<BodyReceptor*>::iterator it = this->world.getReceptors()->begin();
			it != this->world.getReceptors()->end();
			++it)
		{
			(*it)->update(elapsedTime);
		}

		// Updating agents

		eventID = this->SFMLView.CheckEvent();

		int nbAgents = static_cast<int>(agents.size());
		for (int i = 0; i < nbAgents; ++i)
		{
			agents[i]->live();
		}

		this->SFMLView.Draw();

		end_time = std::chrono::high_resolution_clock::now();
		std::cout <<"frame time : "<< std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << std::endl;
	}
}

Simulator::~Simulator(void)
{
}

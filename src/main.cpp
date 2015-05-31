#include "Simulator.h"

using namespace std;

int main(int argc, char* argv[])
{
	Simulator simulator;

	//simulator.CreateWorld();
	simulator.run(sf::seconds(1/60));

	return EXIT_SUCCESS;
}


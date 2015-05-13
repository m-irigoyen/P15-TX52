#include "Simulator.h"

using namespace std;

int main(int argc, char* argv[])
{
	Simulator simulator;

	//simulator.CreateWorld();
	simulator.run(60);

	return EXIT_SUCCESS;
}


#include <cstdlib>
#include <iostream>

#include "controller.h"
#include "Teleport.h"

#include "cube.h"

int main()
{
	vector<std::string> level = { "   ==M=!  X**",
								  " K  =#=  T *@",
								  "    X    ====",
								  "W============" };

	vector<Teleport> teleports = { Teleport(0, 10, 2, 4) };
	
	controller gameController;
	gameController.loadLevel(level, teleports);
	gameController.play();

	std::cin.get();
	std::cin.get();
	
	return EXIT_SUCCESS;
}

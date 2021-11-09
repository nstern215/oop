#include <cstdlib>
#include <iostream>

#include "controller.h"
#include "gameBoard.h"


int main()
{
	gameBoard board(10, 10);

	vector<cube> cubes;

	cubes.emplace_back(1, 1, '#');
	cubes.emplace_back(3, 1, '*');
	cubes.emplace_back(cube(4, 4, '*'));
	cubes.emplace_back(cube(9, 9, '@'));
	cubes.emplace_back(cube(5, 6, 'K'));
	cubes.emplace_back(cube(4, 7, 'M'));

	board.loadLevelCubes(cubes);

	controller gameController(board);
	gameController.play();

	std::cin.get();
	std::cin.get();
	
	return EXIT_SUCCESS;
}

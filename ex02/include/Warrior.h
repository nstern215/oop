#pragma once
#include "cube.h"
class controller;

class Warrior
{
public:
    Warrior();
	Warrior(int col, int row);

	bool move(cube& destination, controller& gameController);

	int getRow() const;
	int getCol() const;

private:
	int m_row;
	int m_col;
};

#pragma once
#include "cube.h"
class controller;

class Mage
{
public:
    Mage();
	Mage(int col, int row);
	
	bool move(cube& destination, controller& gameController);

	int getRow() const;
	int getCol() const;

private:
	int m_row;
	int m_col;
};

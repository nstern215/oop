#pragma once
#include "cube.h"
class controller;

class Mage
{
public:
    Mage();
	Mage(int col, int row, bool active = false);
	void changeActive();

	bool isActive() const;
	void move(cube& destination, controller& gameController);

	int getRow() const;
	int getCol() const;

private:
	bool m_isActive;
	int m_row;
	int m_col;
};

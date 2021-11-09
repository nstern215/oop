#pragma once
#include "cube.h"
class controller;

class Warrior
{
public:
    Warrior();
	Warrior(int col, int row, bool active);
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

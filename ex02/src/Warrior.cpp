#include "Warrior.h"
#include "controller.h"

Warrior::Warrior():
	m_col(3),
	m_row(0)
{
	
}


Warrior::Warrior(int col, int row):
	m_col(col),
	m_row(row)
{
}

int Warrior::getRow() const
{
	return m_row;
}

int Warrior::getCol() const
{
	return m_col;
}

bool Warrior::move(cube& destination, controller& gameController)
{
	// if (gameController.moveToDestination(gameController.getCube(m_row, m_col), destination))
	if (destination.getActiveElement() == 'X')
	{
		int newRow;
		int newCol;

		if (gameController.useTeleport(destination, m_row, m_col, newRow, newCol))
		{
			m_row = newRow;
			m_col = newCol;

			return true;
		}

		return false;
	}
	
	if (destination.getActiveElement() == '!')
		gameController.killOrk(destination);
	
	if (gameController.moveToDestination(m_row, m_col, destination))
	{	
		m_row = destination.getRow();
		m_col = destination.getCol();

		return true;
	}

	return false;
}

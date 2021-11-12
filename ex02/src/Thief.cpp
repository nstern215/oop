#include "Thief.h"
#include "controller.h"

Thief::Thief():
	m_col(1),
	m_row(0)
{}

Thief::Thief(int col, int row):
	m_col(col),
	m_row(row)
{
}

int Thief::getRow() const
{
	return m_row;
}

int Thief::getCol() const
{
	return m_col;
}

bool Thief::move(cube& destination, controller& gameController)
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
	
	if (destination.getActiveElement() == 'F')
		gameController.collectKey(destination);

	if (destination.getActiveElement() == '#' && gameController.isKeyExist())
		gameController.openGate(destination);
	
	if (gameController.moveToDestination(m_row, m_col, destination))
	{
		m_row = destination.getRow();
		m_col = destination.getCol();

		return true;
	}

	return false;
}
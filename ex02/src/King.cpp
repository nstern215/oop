#include "King.h"

#include "controller.h"

King::King():
	m_col(0),
	m_row(0)
{}

King::King(int col, int row):
	m_col(col),
	m_row(row)
{
}

int King::getRow() const
{
	return m_row;
}

int King::getCol() const
{
	return m_col;
}

bool King::move(cube& destination, controller& gameController)
{
	// if (gameController.moveToDestination(gameController.getCube(m_row, m_col), destination))
	if (destination.getActiveElement() == 'X')
	{
		if (gameController.useTeleport(destination, m_row, m_col))
			return true;

		return false;
	}
	if (gameController.moveToDestination(m_row, m_col, destination))
	{
		m_row = destination.getRow();
		m_col = destination.getCol();

		if (destination.getContent() == '@')
			gameController.win();

		return true;
	}

	return false;
}


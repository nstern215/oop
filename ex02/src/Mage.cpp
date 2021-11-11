#include "Mage.h"
#include "controller.h"

Mage::Mage():
	m_col(2),
	m_row(0)
{}

Mage::Mage(int col, int row):
	m_col(col),
	m_row(row)
{
}

int Mage::getRow() const
{
	return m_row;
}

int Mage::getCol() const
{
	return m_col;
}

bool Mage::move(cube& destination, controller& gameController)
{
	// if (gameController.moveToDestination(gameController.getCube(m_row, m_col), destination))
	if (destination.getActiveElement() == '*')
		gameController.killFire(destination);
	
	if (gameController.moveToDestination(m_row, m_col, destination))
	{
		m_row = destination.getRow();
		m_col = destination.getCol();

		return true;
	}

	return false;
}


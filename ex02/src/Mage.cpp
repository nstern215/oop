#include "Mage.h"

Mage::Mage():
	m_col(2),
	m_row(0),
	m_isActive(false)
{}

Mage::Mage(int col, int row, bool active) :
	m_col(col),
	m_row(row),
	m_isActive(active)
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

void Mage::changeActive()
{
	m_isActive = !m_isActive;
}

bool Mage::isActive() const
{
	return m_isActive;
}

void Mage::move(cube& destination, controller& gameController)
{

}


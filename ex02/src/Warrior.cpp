#include "Warrior.h"

Warrior::Warrior():
	m_col(3),
	m_row(0),
	m_isActive(false)
{
	
}


Warrior::Warrior(int col, int row, bool active) :
	m_col(col),
	m_row(row),
	m_isActive(active)
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

void Warrior::changeActive()
{
	m_isActive = !m_isActive;
}

bool Warrior::isActive() const
{
	return m_isActive;
}

void Warrior::move(cube& destination, controller& gameController)
{

}


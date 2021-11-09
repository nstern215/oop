#include "Thief.h"

Thief::Thief():
	m_col(1),
	m_row(0),
	m_isActive(false)
{}

Thief::Thief(int col, int row, bool active) :
	m_col(col),
	m_row(row),
	m_isActive(active)
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

void Thief::changeActive()
{
	m_isActive = !m_isActive;
}

bool Thief::isActive() const
{
	return m_isActive;
}

void Thief::move(cube& destination, controller& gameController)
{

}


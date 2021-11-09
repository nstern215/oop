#include "King.h"

King::King():
	m_col(0),
	m_row(0),
	m_isActive(true)
{}

King::King(int col, int row, bool active):
	m_col(col),
	m_row(row),
	m_isActive(active)
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

void King::changeActive()
{
	m_isActive = !m_isActive;
}

bool King::isActive() const
{
	return m_isActive;
}

void King::move(cube& destination, controller& gameController)
{
	
}


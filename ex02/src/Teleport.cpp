#include "Teleport.h"
#include "controller.h"

Teleport::Teleport(int row, int col, int pairRow, int pairCol):
	m_row(row),
	m_col(col),
	m_pairRow(pairRow),
	m_pairCol(pairCol)
{}

Teleport::Teleport(const Teleport& other):
	m_row(other.getRow()),
	m_col(other.getCol()),
	m_pairRow(other.getPairRow()),
	m_pairCol(other.getPairCol())
{
}

Teleport& Teleport::operator=(const Teleport& other)
{
	if (this != &other)
	{
		m_row = other.getRow();
		m_col = other.getCol();
		m_pairRow = other.getPairRow();
		m_pairCol = other.getPairCol();
	}

	return *this;
}

void Teleport::getPair(const int sourceRow, const int sourceCol, int& pairRow, int& pairCol) const
{
	if (m_row == sourceRow && m_col == sourceCol)
	{
		pairRow = m_pairRow;
		pairCol = m_pairCol;
	}
	else if (m_pairRow == sourceRow && m_pairCol == sourceCol)
	{
		pairRow = m_row;
		pairCol = m_col;
	}
	else
	{
		pairRow = sourceRow;
		pairCol = sourceCol;
	}
}

int Teleport::getRow() const
{
	return m_row;
}

int Teleport::getCol() const
{
	return m_col;
}

int Teleport::getPairRow() const
{
	return m_pairRow;
}

int Teleport::getPairCol() const
{
	return m_pairCol;
}

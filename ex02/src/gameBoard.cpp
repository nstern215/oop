#include "gameBoard.h"

gameBoard::gameBoard():
	m_sizeCol(0),
	m_sizeRow(0)
{
}


gameBoard::gameBoard(int sizeCol, int sizeRow):
	m_sizeCol(sizeCol),
	m_sizeRow(sizeRow)
{
	for (int i = 0; i < m_sizeRow; i++)
	{
		m_board.emplace_back();
		for (int j = 0; j < m_sizeCol; j++)
			m_board[i].emplace_back(i, j);
	}
}

gameBoard::gameBoard(const gameBoard& other):
	m_sizeCol(other.getSizeCol()),
	m_sizeRow(other.getSizeRow()),
	m_board(other.getBoardData())
{}

gameBoard& gameBoard::operator=(const gameBoard& other)
{
	if (this != &other)
	{
		m_sizeRow = other.getSizeRow();
		m_sizeCol = other.getSizeCol();
		m_board = other.getBoardData();
	}

	return *this;
}

void gameBoard::loadLevelCubes(const vector<cube>& level)
{
	for (const auto& c : level)
		m_board[c.getRow()][c.getCol()] = c;
}

vector<vector<cube>> gameBoard::getBoardData() const
{
	return m_board;
}

cube& gameBoard::getCube(int row, int col)
{
	return m_board[row][col];
}

int gameBoard::getSizeRow() const
{
	return m_sizeRow;
}

int gameBoard::getSizeCol() const
{
	return m_sizeCol;
}


#include "gameBoard.h"

using std::nothrow;

//todo: set default configuration for board dimenstion
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


#pragma once

#include <vector>
#include "cube.h"

using std::vector;

class gameBoard
{
public:
	gameBoard() = delete;
	gameBoard(int sizeCol, int sizeRow);
	
	void loadLevelCubes(const vector<cube>& level);
	cube& getCube(int row, int col);
	vector<vector<cube>> getBoardData() const;
	
	int getSizeRow() const;
	int getSizeCol() const;

private:
	const int m_sizeCol;
	const int m_sizeRow;
	//cube** m_board;
	vector<vector<cube>> m_board;
};
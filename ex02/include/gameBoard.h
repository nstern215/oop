#pragma once

#include <vector>
#include "cube.h"

using std::vector;

class gameBoard
{
public:
	gameBoard();
	gameBoard(int sizeCol, int sizeRow);
	gameBoard(const gameBoard& other);
	
	gameBoard& operator=(const gameBoard& other);
	
	void loadLevelCubes(const vector<cube>& level);
	cube& getCube(int row, int col);
	vector<vector<cube>> getBoardData() const;
	
	int getSizeRow() const;
	int getSizeCol() const;

private:
	int m_sizeCol;
	int m_sizeRow;
	//cube** m_board;
	vector<vector<cube>> m_board;
};
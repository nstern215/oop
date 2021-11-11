#pragma once
class cube;
class controller;

class Teleport
{
public:
	Teleport() = default;
	Teleport(const Teleport& other);
	Teleport(int row, int col, int pairRow, int pairCol);

	Teleport& operator=(const Teleport& other);
	
	cube& getPair(const controller& gameController, const int sourceRow, const int sourceCol) const;

	int getRow() const;
	int getCol() const;
	int getPairRow() const;
	int getPairCol() const;

private:
	int m_row;
	int m_col;
	int m_pairRow;
	int m_pairCol;
};
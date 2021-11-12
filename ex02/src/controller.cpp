#include <cstdlib>
#include <iostream>
#include <conio.h>

#include "controller.h"
#include "gameBoard.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Teleport.h"

using std::cout;
using std::endl;


controller::controller():
	m_keyExist(false),
	m_winLevel(false),
	m_activePlayer(KING),
	m_movesCounter(0)
{}

void controller::loadLevel(const vector<std::string>& level, const vector<Teleport>& teleports)
{
	const int rows = level.size();
	if (rows == 0)
	{
		cout << "Cannot load an empty level" << endl;
	}
	
	const int cols = level[0].length();

	m_teleports = teleports;
	m_board = gameBoard(cols, rows);

	vector<cube> levelCubes;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			switch (level[i][j])
			{
			case 'K':
				m_king = King(j, i);
				levelCubes.emplace_back(i, j, ' ',  'K');
				break;
			case 'M':
				m_mage = Mage(j,i);
				levelCubes.emplace_back(i, j, ' ', 'M');
				break;
			case 'T':
				m_thief = Thief(j, i);
				levelCubes.emplace_back(i, j, ' ', 'T');
				break;
			case 'W':
				m_warrior = Warrior(j, i);
				levelCubes.emplace_back(i, j, ' ', 'W');
				break;
			default:
				levelCubes.emplace_back(i, j, level[i][j]);
				break;
			}
		}
	}

	m_board.loadLevelCubes(levelCubes);
}


bool controller::collectKey()
{
	if (m_keyExist)
		return false;

	m_keyExist = true;
	return true;
}

void controller::play()
{
	m_keyExist = false;
	m_movesCounter = 0;

	printBoard();

	for (auto exit = false; !exit && !m_winLevel;)
	{
		auto c = _getch();
		switch(c)
		{
		case 224:
			handleSpecialKey();
			break;
		case 'p':
		case 'P':
			changeActivePlayer();
			break;
		case 27:
			exit = true;
			break;
		default: 
			break;
		}
	}

	system("cls");
	cout << "game over" << endl;
}

void controller::handleSpecialKey()
{
	auto c = _getch();

	switch (c)
	{
	case UP:
		movePlayer(UP);
		break;
	case DOWN:
		movePlayer(DOWN);
		break;
	case LEFT:
		movePlayer(LEFT);
		break;
	case RIGHT:
		movePlayer(RIGHT);
		break;
	}
}

void controller::changeActivePlayer()
{
	m_activePlayer = (Players) ((m_activePlayer + 1) % 4);
	printBoard();
}

void controller::movePlayer(Directions direction)
{
	cube active;
	
	switch (m_activePlayer)
	{
	case KING:
		active = m_board.getCube(m_king.getRow(), m_king.getCol());
		if (validateMove(active.getRow(), active.getCol(), direction))
		{
			cube& dest = calcDestination(active, direction);
			if (m_king.move(dest, *this))
				m_movesCounter++;
		}
		break;
	case THIEF:
		active = m_board.getCube(m_thief.getRow(), m_thief.getCol());
		if (validateMove(active.getRow(), active.getCol(), direction))
		{
			cube& dest = calcDestination(active, direction);
			if (m_thief.move(dest, *this))
				m_movesCounter++;
		}
		break;
	case MAGE:
		active = m_board.getCube(m_mage.getRow(), m_mage.getCol());
		if (validateMove(active.getRow(), active.getCol(), direction))
		{
			cube& dest = calcDestination(active, direction);
			if (m_mage.move(dest, *this))
				m_movesCounter++;
		}
		break;
	case WARRIOR:
		active = m_board.getCube(m_warrior.getRow(), m_warrior.getCol());
		if (validateMove(active.getRow(), active.getCol(), direction))
		{
			cube& dest = calcDestination(active, direction);
			if (m_warrior.move(dest, *this))
				m_movesCounter++;
		}
		break;
	}

	printBoard();
}

bool controller::validateMove(int sourceRow, int sourceCol, Directions direction) const
{
	switch (direction)
	{
	case UP:
		if (sourceRow == 0)
			return false;
		break;
	case DOWN:
		if (sourceRow == m_board.getSizeRow() - 1)
			return false;
		break;
	case LEFT:
		if (sourceCol == 0)
			return false;
		break;
	case RIGHT:
		if (sourceCol == m_board.getSizeCol() - 1)
			return false;
		break;
	}

	return true;
}

void controller::printBoard() const
{
	system("cls");

	for (const vector<cube>& row : m_board.getBoardData())
	{
		for (const cube& col : row)
		{
			cout << col.getActiveElement();
		}

		cout << "\n";
	}

	cout << "\n\n\n";
	
	cout << "Active player: " << getActivePlayer() << endl;
	cout << "Is key available: " << m_keyExist << endl;
	cout << "Num of moves: " << m_movesCounter << endl;
}

std::string controller::getActivePlayer() const
{
	switch(m_activePlayer)
	{
		case KING:
			return "King";
		case THIEF:
			return "Thief";
		case WARRIOR:
			return "Warrior";
		case MAGE:
			return "Mage";
	}

	return "";
}


cube& controller::calcDestination(cube& source, Directions direction)
{
	switch(direction)
	{
		case UP:
			return  m_board.getCube(source.getRow() - 1, source.getCol());
		case DOWN:
			return m_board.getCube(source.getRow() + 1, source.getCol());
		case LEFT:
			return m_board.getCube(source.getRow(), source.getCol() - 1);
		case RIGHT:
			return m_board.getCube(source.getRow(), source.getCol() + 1);
	}

	return source;
}

void controller::collectKey(cube& keyCube)
{
	if (keyCube.getActiveElement() != 'F' || m_keyExist)
		return;

	m_keyExist = true;

	keyCube.removeActiveElement();
}

bool controller::isKeyExist() const
{
	return m_keyExist;
}

gameBoard controller::getBoard() const
{
	return m_board;
}

void controller::killOrk(cube& orkCube)
{
	if (orkCube.getActiveElement() != '!')
		return;

	orkCube.removeActiveElement();
	orkCube.setContent('F');
}

cube& controller::getActivePlayerCube()
{
	switch (m_activePlayer)
	{
	case KING:
		return m_board.getCube(m_king.getRow(), m_king.getCol());
	case MAGE:
		return  m_board.getCube(m_mage.getRow(), m_mage.getCol());
	case THIEF:
		return  m_board.getCube(m_thief.getRow(), m_thief.getCol());
	case WARRIOR:
		return  m_board.getCube(m_warrior.getRow(), m_warrior.getCol());			
	}

	return m_board.getCube(m_king.getRow(), m_king.getCol());
}

cube& controller::getCube(int row, int col)
{
	return m_board.getCube(row, col);
}

bool controller::moveToDestination(int sourceRow, int sourceCol, cube& destination)
{
	return destination.moveIn(m_board.getCube(sourceRow, sourceCol));
}

void controller::killFire(cube& fireCube)
{
	if (fireCube.getActiveElement() != '*')
		return;
	
	fireCube.removeActiveElement();
}

bool controller::openGate(cube& gateCube)
{
	if (!m_keyExist)
		return false;

	gateCube.removeActiveElement();
	m_keyExist = false;
	return true;
}

void controller::win()
{
	m_winLevel = true;
}

bool controller::useTeleport(cube& teleportCube, int sourceRow, int sourceCol, int& newRow, int& newCol)
{
	int pairRow;
	int pairCol;
	
	for (const auto& t : m_teleports)
	{
		t.getPair(teleportCube.getRow(), teleportCube.getCol(), pairRow, pairCol);
		cube& destination = m_board.getCube(pairRow, pairCol);
		if (teleportCube != destination)
		{
			newRow = destination.getRow();
			newCol = destination.getCol();
			return moveToDestination(sourceRow, sourceCol, destination);
		}
	}

	return false;
}


// get move command
// validate destination is in the board
// calc destination cube
// call player to move
// player validate if he can move to destination
// player call controller for relevant action\information (kill ork, collect key etc.)
// player call controller to move to the new destination
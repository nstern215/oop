#include <cstdlib>
#include <iostream>
#include <conio.h>

#include "controller.h"
#include "gameBoard.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

using std::cout;
using std::endl;

controller::controller(gameBoard board):
	m_board(board),
	m_keyExist(false),
	m_activePlayer(KING)
{}

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

	printBoard();

	for (auto exit = false; !exit;)
	{
		auto c = _getch();
		switch(c)
		{
		case 0:
			handleSpecialKey();
			break;
		case 'p':
		case 'P':
			changeActivePlayer();
			break;
		case 27: //escape
			exit = true;
			break;
		default: 
			break;
		}
	}
}

void controller::handleSpecialKey()
{
	
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
			auto dest = calcDestination(active, direction);
			m_king.move(dest, *this);
		}
		break;
	case THIEF:
		active = m_board.getCube(m_thief.getRow(), m_thief.getCol());
		if (validateMove(active.getRow(), active.getCol(), direction))
		{
			auto dest = calcDestination(active, direction);
			m_thief.move(dest, *this);
		}
		break;
	case MAGE:
		active = m_board.getCube(m_mage.getRow(), m_mage.getCol());
		if (validateMove(active.getRow(), active.getCol(), direction))
		{
			auto dest = calcDestination(active, direction);
			m_mage.move(dest, *this);
		}
		break;
	case WARRIOR:
		active = m_board.getCube(m_warrior.getRow(), m_warrior.getCol());
		if (validateMove(active.getRow(), active.getCol(), direction))
		{
			auto dest = calcDestination(active, direction);
			m_warrior.move(dest, *this);
		}
		break;
	}
}

bool controller::validateMove(int sourceRow, int sourceCol, int direction) const
{
	//todo: set directions enum
	switch (direction)
	{
	case 72: //up
		if (sourceRow == 0)
			return false;
		break;
	case 80: //down
		if (sourceRow == m_board.getSizeRow() - 1)
			return false;
		break;
	case 75: //left
		if (sourceCol == 0)
			return false;
		break;
	case 77: //right
		if (sourceCol == m_board.getSizeCol() - 1)
			return false;
		break;
		default:
			return false;
	}

	return true;
}

void controller::printBoard() const
{
	system("cls");

	cout << "Active player: " << m_activePlayer << endl;
	cout << "Is key available: " << m_keyExist << endl;

	cout << "\n\n\n";

	auto boardData = m_board.getBoardData();

	for (const vector<cube>& row : boardData)
	{
		cout << "\t";
		
		for (const cube& col : row)
		{
			cout << col.getActiveElement();
		}

		cout << "\n";
	}
}

const cube& controller::calcDestination(cube& source, Directions direction)
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
		default:
			return source;
	}
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

// get move command
// validate destination is in the board
// calc destination cube
// call player to move
// player validate if he can move to destination
// player call controller for relevant action\information (kill ork, collect key etc.)
// player call controlelr to move to the new destination
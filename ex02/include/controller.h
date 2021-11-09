#pragma once
#include "gameBoard.h"
#include "King.h"
#include "Mage.h"
#include "Thief.h"
#include "Warrior.h"

enum Players
{
	KING = 0,
	WARRIOR = 1,
	THIEF = 2,
	MAGE = 3
};

enum Directions
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};

class controller
{
public:
	controller(gameBoard board);

	bool collectKey();

	gameBoard getBoard() const;
	bool isKeyExist() const;

	void play();

	void collectKey(cube& keyCube);
	void killOrk(cube& orkCube);
	void useTeleport(cube& teleportCube);
	void moveToDestination(cube& source, cube& destination);

private:
	void printBoard() const;
	void handleSpecialKey();
	void changeActivePlayer();
	void movePlayer(Directions direction);
	cube& getActivePlayerCube() const;
	const cube& calcDestination(cube& source, Directions direction);
	bool validateMove(int sourceRow, int sourceCol, int direction) const;
	
	gameBoard m_board;
	bool m_keyExist;
	
	King m_king;
	Mage m_mage;
	Thief m_thief;
	Warrior m_warrior;

	Players m_activePlayer;
};

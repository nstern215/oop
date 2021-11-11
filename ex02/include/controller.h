#pragma once
#include "gameBoard.h"
#include "King.h"
#include "Mage.h"
#include "Thief.h"
#include "Warrior.h"

class Teleport;

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
	controller();
	
	bool collectKey();

	gameBoard getBoard() const;
	bool isKeyExist() const;

	void play();

	void collectKey(cube& keyCube);
	void killOrk(cube& orkCube);
	void win();
	void killFire(cube& fireCube);
	bool openGate(cube& gateCube);
	bool useTeleport(cube& teleportCube, int sourceRow, int sourceCol);
	bool moveToDestination(int sourceRow, int sourceCol, cube& destination);
	cube& getCube(int row, int col);

	void loadLevel(const vector<std::string>& level, const vector<Teleport>& teleports);

private:
	void printBoard() const;
	void handleSpecialKey();
	void changeActivePlayer();
	void movePlayer(Directions direction);
	cube& getActivePlayerCube();
	cube& calcDestination(cube& source, Directions direction);
	std::string getActivePlayer() const;
	bool validateMove(int sourceRow, int sourceCol, Directions direction) const;
	
	bool m_keyExist;
	bool m_winLevel;
	unsigned int m_movesCounter;

	gameBoard m_board;
	vector<Teleport> m_teleports;
	
	King m_king;
	Mage m_mage;
	Thief m_thief;
	Warrior m_warrior;

	Players m_activePlayer;
};

#pragma once
#include "Board.hpp"
#include <string>

#define CONSOLE

#ifdef CONSOLE
	#include <iostream>
#endif

class Player {
public:
	Player();
	Player(std::string);
	Player(std::string, Weapon);
	~Player();

	void move();
	std::string getName();

	void setWeapon(Weapon playerWeapon);
	void setBoard(Board* playerBoard);

private:
	std::string name;
	Weapon weapon;
	Board* board;
};


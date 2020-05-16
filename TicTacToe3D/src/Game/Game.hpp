#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include <string>

#define CONSOLE // TODO -> check if works in driver

#ifdef CONSOLE
	#include <iostream>
#endif 

enum GameState {
	Closed, 
	Running, 
	Paused
};

enum Result {
	Draw,
	Win1, 
	Win2
};

class Game {
public:
	Game();
	// if reverseOrderOfWeapons is true firstPlayer gets 'O', second - 'X'
	Game(Player* firstPlayer, Player* secondPlayer, bool reverseOrderOfWeapons = false);
	~Game();

	void start();
	void end();
	void pause();

private:
	Player** players;
	Board* board;
	GameState state;

	Result result;

private:
	BoardState checkBoardState();
	Player* getWinner();
};


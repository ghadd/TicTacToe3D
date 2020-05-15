#pragma once

#define CONSOLE

#ifdef CONSOLE

#include <iostream>
#include <string>

#endif 

typedef unsigned short ushort;

enum BoardState {
	OK, HasWinner, HasNoMoves
};

enum Weapon {
	X, O, Nothing
};

class Board {
public:
	Board();
	~Board();

	ushort& value(ushort, ushort, ushort);
	void setValue(ushort, ushort, ushort, ushort);
	
	bool hasEmptyCell();
	bool hasWinner();

	void display();

private:
	/* 
	 * 0 - X
	 * 1 - O
	 * 2 - Empty
	 */
	ushort* board;
};


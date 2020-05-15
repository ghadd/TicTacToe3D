#include "Board.hpp"
#include <cmath>

const size_t side = 3;
const size_t numberOfCells = pow(side, 3);

Board::Board() {
	this->board = new ushort[numberOfCells];
	for (int i = 0; i < numberOfCells; i++) this->board[i] = Nothing;
}

Board::~Board()
{
	delete[] this->board;
}

ushort& Board::value(ushort x, ushort y, ushort z)
{
	return this->board[x + y * side + z * side * side];
}

void Board::display() {
	for (int i = 0; i < side; i++) {
		std::cout << "Plate " + std::to_string(i) << std::endl;
		for (int j = 0; j < side; j++) {
			for (int k = 0; k < side; k++) {
				ushort& val = this->value(i, j, k);
				switch (val)
				{
				case X:
					std::cout << "X ";
					break;
				case O:
					std::cout << "O ";
					break;
				case Nothing:
					std::cout << "- ";
					break;
				default:
					break;
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

void Board::setValue(ushort x , ushort y, ushort z, ushort value) {
	this->board[x + y * side + z * side * side] = value;
}

bool Board::hasEmptyCell() {
	for (int i = 0; i < numberOfCells; i++) {
		if (this->board[i] == Nothing) return true;
	}
	return false;
}

bool Board::hasWinner() {
	// TODO -> logics

	return false;
}

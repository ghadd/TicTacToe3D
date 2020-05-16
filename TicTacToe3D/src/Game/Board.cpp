#include "Board.hpp"

Board::Board() {
	DIRECTIONS.reserve(FLAT_DIRECTIONS.size() + DEPTH_DIRECTIONS.size());
	DIRECTIONS.insert(DIRECTIONS.end(), FLAT_DIRECTIONS.begin(), FLAT_DIRECTIONS.end());
	DIRECTIONS.insert(DIRECTIONS.end(), DEPTH_DIRECTIONS.begin(), DEPTH_DIRECTIONS.end());

	this->board = new short[numberOfCells];
	for (int i = 0; i < numberOfCells; i++) this->board[i] = Nothing;
}

Board::~Board() {
	delete[] this->board;
}

short& Board::value(const Point3D& point) const {
	return this->board[point.flat()];
}

void Board::setValue(const Point3D& point, short value) {
	this->board[point.flat()] = value;
}

std::pair<bool, Point3D> Board::checkDirections(const Point3D& start) const {
	if (this->value(start) == Nothing)
		return std::make_pair(false, Point3D());

	for (auto& DIR : DIRECTIONS) {
		const Point3D secondPoint = start + DIR;
		if (!secondPoint.valid()) continue;

		if (this->value(start) == this->value(secondPoint)) {
			const Point3D thirdPoint = secondPoint + DIR;
			if (!thirdPoint.valid()) continue;

			if (this->value(secondPoint) == this->value(thirdPoint)) {
				return std::make_pair(true, DIR);
			}
		}
	}

	return std::make_pair(false, Point3D());
}

bool Board::hasEmptyCell() {
	for (int i = 0; i < numberOfCells; i++) {
		if (this->board[i] == Nothing) return true;
	}
	return false;
}

WinCheck Board::hasWinner() {
	// TODO -> logics
	for (short i = 0; i < side; i++) {
		for (short j = 0; j < side; j++) {
			for (short k = 0; k < side; k++) {
				std::pair<bool, Point3D> res = this->checkDirections({ i, j, k });
				if (res.first == true) {
					return { true, {i, j, k},  res.second };
				}
			}
		}
	}

	return { false, Point3D(), Point3D() };
}

void Board::display() {
	for (short i = 0; i < side; i++) {
		std::cout << "Plate " + std::to_string(i) << std::endl;
		for (short j = 0; j < side; j++) {
			for (short k = 0; k < side; k++) {
				short& val = this->value({ i, j, k });
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

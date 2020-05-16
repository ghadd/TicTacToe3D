#pragma once

#define CONSOLE

#ifdef CONSOLE
#include <iostream>
#endif

#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <vector>

#include "../assets/Point3D.hpp"

enum BoardState {
	OK, HasWinner, HasNoMoves
};

enum Weapon {
	X, O, Nothing
};

const size_t side = 3;
const size_t numberOfCells = pow(side, 3);

const std::vector<Point3D> FLAT_DIRECTIONS =
{ {0, -1, -1}, {0, -1, 0}, {0, -1, 1},
  {0,  0, -1},             {0,  0, 1},
  {0,  1, -1}, {0,  1, 0}, {0,  1, 1} };
const std::vector<Point3D> DEPTH_DIRECTIONS =
{ {1, -1, -1}, {1, -1, 0}, {1, -1, 1},
  {1,  0, -1}, {1,  0, 0}, {1,  0, 1},
  {1,  1, -1}, {1,  1, 0}, {1,  1, 1} };

struct WinCheck {
	bool win;
	Point3D start, dir;
};

class Board {
public:
	Board();
	~Board();

	short& value(const Point3D&) const;
	void setValue(const Point3D&, short);

	bool hasEmptyCell();
	WinCheck hasWinner();

	std::pair<bool, Point3D> checkDirections(const Point3D&) const;

	void display();

private:
	/*
	 * 0 - X
	 * 1 - O
	 * 2 - Empty
	 */
	short* board;
	std::vector<Point3D> DIRECTIONS;
};
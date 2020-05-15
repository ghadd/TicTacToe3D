#include "Game.hpp"

Game::Game() {
	this->players = new Player*[2];
	this->players[0] = new Player("unknown");
	this->players[1] = new Player("unknown");
	this->board = nullptr;
	this->state = Closed;
}

Game::Game(Player* firstPlayer, Player* secondPlayer, bool reverseOrderOfWeapons) {
	this->players = new Player * [2];
	if (reverseOrderOfWeapons) {
		players[X] = secondPlayer;
		players[O] = firstPlayer;
		firstPlayer->setWeapon(O);
		secondPlayer->setWeapon(X);
	}
	else {
		players[X] = firstPlayer;
		players[O] = secondPlayer;
		firstPlayer->setWeapon(X);
		secondPlayer->setWeapon(O);
	}
	this->board = nullptr;
	this->state = GameState::Closed;
}

Game::~Game() {
}

void Game::start() {
	this->board = new Board;
	this->players[0]->setBoard(this->board);
	this->players[1]->setBoard(this->board);

	this->state = GameState::Running;

	while (this->state == GameState::Running) {
		if (this->checkBoardState() != BoardState::OK) {
			// TODO -> display end results
			this->state = GameState::Closed;
			break;
		}

		this->players[X]->move();
		this->players[O]->move();
	}
}

BoardState Game::checkBoardState()
{
	if (!this->board->hasEmptyCell()) return BoardState::HasNoMoves;
	if (this->board->hasWinner()) return BoardState::HasWinner;

	return BoardState::OK;
}

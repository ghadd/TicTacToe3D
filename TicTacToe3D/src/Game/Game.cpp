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
		this->players[X]->move();

		BoardState boardState = this->checkBoardState();
		if (boardState != BoardState::OK) {
			if (boardState == BoardState::HasWinner) {
				this->result = Result::Win1;

#ifdef CONSOLE
				std::cout << "Player " + this->players[X]->getName() + " won" << std::endl;
#endif // CONSOLE
			}
			else {
				this->result = Result::Draw;
				
#ifdef CONSOLE
				std::cout << "Game ended. It's a draw." << std::endl;
#endif // CONSOLE
			}

			this->state = GameState::Closed;
			break;
		}

		this->players[O]->move();

		boardState = this->checkBoardState();
		if (boardState != BoardState::OK) {
			if (boardState == BoardState::HasWinner) {
				this->result = Result::Win2;
#ifdef CONSOLE
				std::cout << "Player " + this->players[X]->getName() + " won" << std::endl;
#endif // CONSOLE
			}
			else {
				this->result = Result::Draw;

#ifdef CONSOLE
				std::cout << "Game ended. It's a draw." << std::endl;
#endif // CONSOLE
			}

			this->state = GameState::Closed;
			break;
		}
	}
}

BoardState Game::checkBoardState()
{
	if (!this->board->hasEmptyCell()) return BoardState::HasNoMoves;
	if (this->board->hasWinner().win) return BoardState::HasWinner;

	return BoardState::OK;
}

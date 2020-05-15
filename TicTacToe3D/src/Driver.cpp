#include "Game/Game.hpp"
#include "Game/Player.hpp"

int main() {
	Game game(new Player("dan1"), new Player("dan2"));
	game.start();

	return 0;
}
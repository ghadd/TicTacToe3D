#include "Player.hpp"

Player::Player() {
	this->name = "unknown";
	this->weapon = Nothing;
	this->board = nullptr;
}

Player::Player(std::string playerName) {
	this->name = playerName;
	this->weapon = Nothing;
	this->board = nullptr;
}

Player::Player(std::string playerName, Weapon playerWeapon) {
	this->name = playerName;
	this->weapon = playerWeapon;
	this->board = nullptr;
}

Player::~Player() {}

void Player::move() {
	std::cout << this->name << ", it's your turn." << std::endl;

	int x, y, z;
	std::cout << "Enter your move in 3 dimensions: ";
	std::cin >> x >> y >> z;

	while (this->board->value(x, y, z) != Nothing) {
		std::cout << "This cell is not empty. Choose another one: ";
		std::cin >> x >> y >> z;
	}

	this->board->setValue(x, y, z, this->weapon);
	std::cout << std::endl;

	std::cout << "Okay. Current state is: " << std::endl;
	this->board->display();
}

void Player::setWeapon(Weapon playerWeapon) {
	this->weapon = playerWeapon;
}

void Player::setBoard(Board* playerBoard) {
	this->board = playerBoard;
}

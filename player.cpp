#include "player.h"

#include <iostream>
#include <string>

Player::Player() {
	move = Move::NOT_SET;
}

void Player::setMove() {
	std::string userInput;

	while (true) {
		std::cout << "-------------------------\n";
		std::cout << "What's your Move?\n";
		std::cout << "a. Rock\n";
		std::cout << "b. Paper\n";
		std::cout << "c. Scissors\n";

		std::cout << "Enter your choice: ";
		std::cin >> userInput;

		if (userInput.compare("a") == 0) {
			move = Move::ROCK;
			break;
		}
		else if (userInput.compare("b") == 0) {
			move = Move::PAPER;
			break;
		}
		else if (userInput.compare("c") == 0) {
			move = Move::SCISSORS;
			break;
		}
		else {
			std::cout << "Error: invalid input!\n\n";
		}
	}
}

void Player::setMoveGui(Move move) {
	this->move = move;
	moveIsSet = true;
	std::cout << "Player move is set from GUI." << std::endl;
}

Move Player::getMove() {
	Move currentMove = move;
	moveIsSet = false;
	move = Move::NOT_SET;
	return currentMove;
}
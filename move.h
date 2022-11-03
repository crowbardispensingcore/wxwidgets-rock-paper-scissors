#pragma once

#include <iostream>

using std::string;

enum class Move {
	ROCK,
	PAPER,
	SCISSORS,
	NOT_SET
};

static string moveEnumToString(Move move) {
	switch (move) {
		case Move::ROCK:
			return "Rock";
		case Move::PAPER:
			return "Paper";
		case Move::SCISSORS:
			return "Scissors";
		default:
			return "Not Set";
	}
}
#include "bot.h"
#include "move.h"
#include <iostream>
#include <string>
#include <stdlib.h>


void Bot::set_choice() {
	int temp = rand() % 3 + 1;    //generate random number between 1 and 3
	switch (temp) {
	case 1:
		choice = Move::ROCK;
		break;
	case 2:
		choice = Move::PAPER;
		break;
	case 3:
		choice = Move::SCISSORS;
		break;
	}
}

void Bot::update_sequence(string choice) {
	if (sequence.size() == 5) {
		sequence.pop_back();
		sequence.push_front(choice);
	}
	else {
		sequence.push_front(choice);
	}
}

void Bot::set_choiceML(Move player_choice){
	update_sequence(convert_Move_to_str(player_choice));
	if (sequence.size() < 5) {
		this->set_choice();
		update_sequence(convert_Move_to_str(this->get_choice()));
		return;
	}
	else {
		string seq = sequence[0] + sequence[1] + sequence[2] + sequence[3] + sequence[4];
		umap[seq]++;
		string curr_seq = sequence[0] + sequence[1] + sequence[2] + sequence[3];
		Move return_Move;
		int rock = umap[curr_seq + "R"];
		int paper = umap[curr_seq + "P"];
		int scissor = umap[curr_seq + "S"];
		if (rock > paper && rock > scissor) {
			if (paper > scissor) {
				prediction = Move::PAPER;
			}
			else {
				prediction = Move::SCISSORS;
			}

			choice = Move::ROCK;
		}
		else if (paper > rock && paper > scissor) {
			if (rock > scissor) {
				prediction = Move::ROCK;
			}
			else {
				prediction = Move::SCISSORS;
			}

			choice = Move::PAPER;
		}
		else if (scissor > rock && scissor > paper) {
			if (rock > paper) {
				prediction = Move::ROCK;
			}
			else {
				prediction = Move::PAPER;
			}

			choice = Move::SCISSORS;
		}
		else {
			this->set_choice();
		}
		update_sequence(convert_Move_to_str(this->get_choice()));
		return;
	}
}

string Bot::convert_Move_to_str(Move player_choice) {
	if (player_choice == Move::ROCK) {
		return "R";
	}
	else if (player_choice == Move::PAPER) {
		return "P";
	}
	else {
		return "S";
	}
}

Move Bot::get_choice() {
	return choice;
}
string Bot::print_choice() {
	switch (choice) {
	case Move::ROCK:
		return "Rock";
	case Move::PAPER:
		return "Paper";
		break;
	case Move::SCISSORS:
		return "Scissors";
		break;
	default:
		return "NOT_SET";
		break;
	}
}

Move Bot::getPrediction() {
	return prediction;
}

void Bot::resetML() {
	sequence.clear();
	umap.clear();
}

void Bot::saveFrequencyToFile() {
	ofstream fileStream;
	fileStream.open("frequency.txt");
	for (auto i = umap.begin(); i != umap.end(); i++) {
		fileStream << i->first << ": " << i->second << "\n";
	}
}
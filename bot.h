#pragma once

#include <fstream>
#include <string>
#include <unordered_map>
#include <deque>
#include "move.h"
using namespace std;
class Bot {
private:
	Move choice;
	Move prediction;
	deque <string> sequence;
	unordered_map<string, int> umap;
public:
	void set_choice();
	void set_choiceML(Move player_choice);
	void update_sequence(string choice);
	string convert_Move_to_str(Move player_choice);
	Move get_choice();
	Move getPrediction();
	string print_choice();

	void saveFrequencyToFile();

	void resetML();
};

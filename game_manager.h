#pragma once

#include <iostream>
#include <time.h>
#include "bot.h"
#include "player.h"

class GameManager {
private:
	Player game_player;
	Bot game_bot;
public:
	void startGame(char gameType, int roundCount);
	int decideWinner(Move player_choice, Move bot_choice);
};

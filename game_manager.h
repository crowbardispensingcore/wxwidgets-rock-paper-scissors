#pragma once

#include <iostream>
#include <time.h>
#include "bot.h"
#include "player.h"

class GameManager {
public:
	int remainingRoundCount = 20;
	int playerWinCount = 0;
	int aiWinCount = 0;
	int tieCount = 0;

	Player* player;
	Bot* bot;

	GameManager(Player* player, Bot* bot);
	void startGame(char gameType, int roundCount);
	int decideWinner(Move player_choice, Move bot_choice);

	void initGame(int roundCount);

private:

};

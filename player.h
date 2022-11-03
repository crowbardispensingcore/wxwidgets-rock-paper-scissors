#pragma once

#include "move.h"

class Player {
private:
	Move move;
public:
	bool moveIsSet = true;

	Player();
	void setMove();
	void setMoveGui(Move move);
	Move getMove();
};

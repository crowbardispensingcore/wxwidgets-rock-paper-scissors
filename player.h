#pragma once

#include "move.h"

class Player {
private:
	Move move;
public:
	Player();
	void setMove();
	Move getMove();
};

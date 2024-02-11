#pragma once
#include "player.h"
#include "../Classes/Board/board.hpp"

class AI : public Player
	{
	public:
		AI();
		AI(char t, bool f);

		int play_turn(Board* board);
	private:
		int recur_turn(Board* board, char type);






	};

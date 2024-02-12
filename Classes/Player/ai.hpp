#pragma once
#include "player.h"
#include <list>
#include "../Classes/Board/board.hpp"

class AI : public Player
	{
	public:
		AI();
		AI(char t, bool f);

		int play_turn(Board* board);
	private:
		int minmax_recur(Board* board, int depth, bool ai, char aitype, char playertype);
		int minmax(Board* board, char aitype);






	};

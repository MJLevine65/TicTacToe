#pragma once
#include "player.h"

class AI : public Player
	{
	public:
		AI();
		AI(char t, bool f);

		int play_turn(char board[]);
	private:
		int recur_turn(char board[], bool player);






	};

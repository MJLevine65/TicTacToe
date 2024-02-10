#pragma once
#include "../Button.h"
#include <random>
#include <algorithm>




class Player {
	public:
		char type;
		bool turn;

		Player();
		Player(char t, bool f);
	protected:
		bool check_board(char board[]);
		bool board_full(char board[]);
};





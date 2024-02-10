#pragma once
#include "player.h"

class User : public Player
{
	public: 
		//Constructors
		User();
		User(char t, bool f);

		int play_turn(int tile, char board[]);


};
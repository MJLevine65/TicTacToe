#pragma once
#include "player.h"
#include "../Classes/Board/board.hpp"

class User : public Player
{
	public: 
		//Constructors
		User();
		User(char t, bool f);

		int play_turn(int tile, Board b);


};
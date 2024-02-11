#pragma once
#include "../Classes/Button/button.hpp"
#include "../Classes/Board/board.hpp"
#include <random>
#include <algorithm>




class Player {
	public:
		char type;
		bool turn;
		Player();
		Player(char t, bool f);
};





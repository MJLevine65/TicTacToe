#pragma once
#include <array>

class Board
	{
	public:
		std::array<char,9> board;
		Board();
		Board(std::array<char,9>* board);
		bool check_board(char type);
		bool board_full();
		Board copy();




};
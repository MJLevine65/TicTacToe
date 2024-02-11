#include "board.hpp"
#include <array>
std::array<char, 9> board;

Board::Board() {
	this->board = {'-','-','-','-','-','-','-','-','-'};
};

Board::Board(std::array<char, 9>* board) {
	this->board = *board;
}

bool Board::check_board(char type) {
	//Returns True if a Player has a winning combination, false otherwise
	if (board[0] == type) {
		if (board[1] == type && board[2] == type || board[3] == type && board[6] == type) {
			return true;
		}
	}
	if (board[4] == type) {
		if (board[0] == type && board[8] == type || board[2] == type && board[6] == type ||
			board[1] == type && board[7] == type || board[3] == type && board[5] == type) {
			return true;
		}
	}
	if (board[8] == type) {
		if (board[2] == type && board[5] == type || board[6] == type && board[7] == type) {
			return true;
		}
	}
	return false;

}

bool Board::board_full() {
	//Check if every space on the board is filled
	for (int i = 0; i < 9;i++) {
		if (board[i] == '-') { return false; }
	}
	return true;
}

Board Board::copy() {
	//Create a deep copy
	auto boardtwo = board;
	return Board(&boardtwo);
}

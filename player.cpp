#include "player.h"


char type;
bool turn;

bool Player::check_board(char board[]) {
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
bool Player::board_full(char board[]) {
	for (int i = 0; i < 9;i++) {
		if (board[i] == '-') { return false; }
	}
	return true;
}
Player::Player() {};

Player::Player(char t, bool f) {
	this->type = t;
	this->turn = f;
}





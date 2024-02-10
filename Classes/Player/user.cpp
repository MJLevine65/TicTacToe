#include "user.hpp"


User::User() { 
	this->turn = false; 
};
User::User(char t, bool f) : Player(t, f) {

}

int User::play_turn(int tile, char board[]) {
	board[tile] = this->type;
	if (check_board(board)) { return 2; }
	if (board_full(board)) { return 1; }
	return 0;
}

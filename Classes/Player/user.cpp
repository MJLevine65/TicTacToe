#include "user.hpp"


User::User() { 
	this->turn = false; 
};
User::User(char t, bool f) : Player(t, f) {

}

int User::play_turn(int tile, Board board) {
	board.board[tile] = this->type;
	if (board.check_board(this->type)) { return 2; }
	if (board.board_full()) { return 1; }
	return 0;
}

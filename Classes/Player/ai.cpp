#include "ai.hpp"
#include <iostream>
#include <list>
#include <algorithm>

int AI::minmax_recur(Board* board,int depth, bool ai, char aitype, char playertype) {
	if ((*board).check_board(aitype)) {
		return 10 - depth;
		
	}
	if ((*board).check_board(playertype)) {
		return -10 + depth;
	}

	if ((*board).board_full()) {
		return 0;
	}
	int score;
	if (ai) {
		score = -100;
		for (int i = 0; i < 9;i++) {
			if ((*board).board[i] == '-') {

				//Get score for this move
				(*board).board[i] = aitype;
				int val = minmax_recur(board, depth + 1, false, aitype, playertype);
				(*board).board[i] = '-';

				score = std::max(score, val);


			}
		}

	}

	else {
		score = 100;
		for (int i = 0; i < 9;i++) {
			if ((*board).board[i] == '-') {

				//Get score for this move
				(*board).board[i] = playertype;
				int val = minmax_recur(board, depth + 1, true, aitype, playertype);
				(*board).board[i] = '-';

				score = std::min(score, val);


			}
		}


	}
	return score;


}
int AI::minmax(Board* board, char aitype) {
	int best = -1;
	int maxval = -100;
	char playertype;
	if (aitype == 'X') { playertype = 'O'; } 
	else { playertype = 'X'; }
	
	for (int i = 0; i < 9;i++) {
		if ((*board).board[i] == '-') {

			//Get score for this move
			(*board).board[i] = aitype;
			int val = minmax_recur(board, 0, false, aitype, playertype);
			(*board).board[i] = '-';

			if (val > maxval) {
				maxval = val;
				best = i;
			}

		}
	}
	return best;

}


AI::AI() { this->turn = false; };
AI::AI(char t, bool f) : Player(t, f) {

}
int AI::play_turn(Board *board) {
	//Takes the game board as input,output is state of the game

	//Create a new board with the values of board
	Board board2 = (*board).copy();
	//Make AI selection of what space to pick
	int choice;
	//choice = recur_turn(&board2, this->type);
	choice = minmax(board, this->type);
	(*board).board[choice] = this->type;
	//AI won
	if ((*board).check_board(this->type)) { return 2; }
	//Tie
	if ((*board).board_full()) { return 1; }
	//Continue Game
	return 0;
}

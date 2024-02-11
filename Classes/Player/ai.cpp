#include "ai.hpp"
#include <iostream>




int AI::recur_turn(Board board, char type) {
	/*
	bool recur(char board[], char aitype, char othertype, int poss) {

	};*/

	std::vector<int> possNums;
	for (int i = 0; i < sizeof(board.board); i++) {
		if (board.board[i] == '-') {
			possNums.push_back(i);

			//If picking this tile would win return this tile as selection
			board.board[i] = this->type;
			if (board.check_board(this->type)) {return i;}
			else { board.board[i] = '-';}
		}
	}
	if (possNums.size() == 1){return possNums[0];}

	
		
	int index = rand() % possNums.size();
	std::cout << "size " << possNums.size() << std::endl;

	return possNums[index];


}

AI::AI() { this->turn = false; };
AI::AI(char t, bool f) : Player(t, f) {

}
int AI::play_turn(Board board) {
	//Takes the game board as input,output is state of the game

	//Create a new board with the values of board
	Board board2 = board.copy();
	//Make AI selection of what space to pick
	int choice;
	choice = recur_turn(board2, this->type);
	std::cout << "choice " << choice << std::endl;
	board.board[choice] = this->type;
	//AI won
	if (board.check_board(this->type)) { return 2; }
	//Tie
	if (board.board_full()) { return 1; }
	//Continue Game
	return 0;
}

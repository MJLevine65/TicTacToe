#pragma once
#include "button.h"
#include <random>
#include <algorithm>
class Player
{
public:
	char type;
	bool turn;
protected:
	bool check_board(char board[]) {
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
	bool board_full(char board[]) {
		for (int i = 0; i < 9;i++) {
			if (board[i] == '-') { return false; }
		}
		return true;
	}
public:
	Player() {};

	Player(char t, bool f) {
		this->type = t;
		this->turn = f;
	}
};

class User: public Player
{
public:
	User() { this->turn = false; };
	User(char t,bool f) : Player(t,f) {

	}

	int play_turn(int tile,char board[]) {
		board[tile] = this->type;
		if (check_board(board)) {return 2; }
		if(board_full(board)){return 1;}
		return 0;
	}
};

class AI: public Player
{

private: 
	int recur_turn(char board[], bool player) {
		std::vector<int> possNums;
		for (int i = 0; i < sizeof(board); i++) {
			if (board[i] == '-') {
				possNums.push_back(i);
				board[i] == this->type;
				if (check_board(board)) {
					return i;
				}
				else {
					board[i] = '-';
				}
			}
		}
		int index = rand() % possNums.size();
		std::cout << "size " << possNums.size() << std::endl;

		return possNums[index];


	}
public:
	AI() { this->turn = false; };
	AI(char t, bool f) : Player(t, f) {

	}
	int play_turn(char board[]) {
		char board2[sizeof(board)];
		std::copy_n(board, sizeof(board), board2);
		int choice;
		choice = recur_turn(board2, true);
		std::cout << "choice " << choice << std::endl;
		board[choice] = this->type;
		if (check_board(board)) { return 2; }
		if (board_full(board)) { return 1; }
		return 0;
	}
};


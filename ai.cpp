#include "ai.hpp"




int AI::recur_turn(char board[], bool player) {
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

AI::AI() { this->turn = false; };
AI::AI(char t, bool f) : Player(t, f) {

}
int AI::play_turn(char board[]) {
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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, answer = 0;

void move_left(vector<vector<int>>& board) {
	for (int i = 0; i < n; i++) {
		vector<int> stack, board_line;
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) {
				stack.push_back(board[i][j]);
			}
		}

		if (stack.size() >= 1) {
			for (auto it = stack.begin(); it != stack.end(); it++) {
				if ((it + 1) != stack.end() && *it == *(it + 1)) {
					board_line.push_back(*it * 2);
					it++;
				}
				else {
					board_line.push_back(*it);
				}
			}
		}

		for (int j = 0; j < n; j++) {
			board[i][j] = (j < board_line.size()) ? board_line[j] : 0;
		}
	}
}

void move_right(vector<vector<int>>& board) {
	for (int i = 0; i < n; i++) {
		vector<int> stack, board_line;
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) {
				stack.push_back(board[i][j]);
			}
		}

		if (stack.size() >= 1) {
			for (int i = stack.size() - 1; i >= 0; i--) {
				if (i - 1 >= 0 && stack[i] == stack[i - 1]) {
					board_line.insert(board_line.begin(), (stack[i] * 2));
					--i;
				}
				else {
					board_line.insert(board_line.begin(), (stack[i]));
				}
			}
		}

		for (int j = 0; j < n; j++) {
			board[i][(n - j - 1)] = (j < board_line.size()) ? board_line[(board_line.size() - j - 1)] : 0;
		}
	}
}

void move_up(vector<vector<int>>& board) {
	for (int i = 0; i < n; i++) {
		vector<int> stack, board_line;
		for (int j = 0; j < n; j++) {
			if (board[j][i] != 0) {
				stack.push_back(board[j][i]);
			}
		}

		if (stack.size() >= 1) {
			for (auto it = stack.begin(); it != stack.end(); it++) {
				if ((it + 1) != stack.end() && *it == *(it + 1)) {
					board_line.push_back(*it * 2);
					it++;
				}
				else {
					board_line.push_back(*it);
				}
			}
		}

		for (int j = 0; j < n; j++) {
			board[j][i] = (j < board_line.size()) ? board_line[j] : 0;
		}
	}
}

void move_down(vector<vector<int>>& board) {
	for (int i = 0; i < n; i++) {
		vector<int> stack, board_line;
		for (int j = 0; j < n; j++) {
			if (board[j][i] != 0) {
				stack.push_back(board[j][i]);
			}
		}

		if (stack.size() >= 1) {
			for (int i = stack.size() - 1; i >= 0; i--) {
				if (i - 1 >= 0 && stack[i] == stack[i - 1]) {
					board_line.insert(board_line.begin(), (stack[i] * 2));
					--i;
				}
				else {
					board_line.insert(board_line.begin(), (stack[i]));
				}
			}
		}

		for (int j = 0; j < n; j++) {
			board[(n - j - 1)][i] = (j < board_line.size()) ? board_line[(board_line.size() - j - 1)] : 0;
		}
	}
}

void dfs(vector<vector<int>> board, int direction, int depth) {
	if (depth >= 5) {
		for (int i = 0; i < n; i++) {
			answer = max(*max_element(board[i].begin(), board[i].end()), answer);
		}
		return;
	}

	if (direction == 0)	move_left(board);
	if (direction == 1)	move_right(board);
	if (direction == 2)	move_up(board);
	if (direction == 3)	move_down(board);

	for (int i = 0; i < 4; i++) {
		dfs(board, i, depth + 1);
	}
}

int solution(vector<vector<int>>& board) {
	for (int i = 0; i < 4; i++) {
		dfs(board, i, 0);
	}

	return answer;
}

int main(void) {
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	cout << solution(board);

	return 0;
}
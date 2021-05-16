#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void move_left(vector<vector<int>>& board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size() - 1; j++) {
			if (board[i][j] == board[i][j + 1]) {
				board[i][j] *= 2;
				board[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size() - 1; j++) {
			if (board[i][j] != 0) {
				int k = j - 1;
				while (k > 0 && board[i][k] == 0) {
					--k;
				}
				board[i][k + 1] = board[i][j];
				board[i][j] = 0;
			}
		}
	}
}

void move_right(vector<vector<int>>& board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = board.size() - 1; j > 0; j--) {
			if (board[i][j] == board[i][j - 1]) {
				board[i][j] *= 2;
				board[i][j - 1] = 0;
			}
		}
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = board.size() - 1; j > 0; j--) {
			if (board[i][j] != 0) {
				int k = j + 1;
				while (k > 0 && board[i][k] == 0) {
					++k;
				}
				board[i][k - 1] = board[i][j];
				board[i][j] = 0;
			}
		}
	}
}

void move_up(vector<vector<int>>& board) {
	for (int j = 0; j < board.size(); j++) {
		for (int i = board.size() - 1; i > 0; i--) {
			if (board[i][j] == board[i][j - 1]) {
				board[i][j] *= 2;
				board[i][j - 1] = 0;
			}
		}
	}

	for (int j = 0; j < board.size(); j++) {
		for (int i = board.size() - 1; i > 0; i--) {
			if (board[i][j] != 0) {
				int k = j - 1;
				while (k > 0 && board[k][j] == 0) {
					++k;
				}
				board[k - 1][j] = board[i][j];
				board[i][j] = 0;
			}
		}
	}
}

void move_down(vector<vector<int>>& board) {

}

void dfs(vector<vector<int>> board, int direction, int depth) {
	if (depth >= 5) {
		for (int i = 0; i < board.size(); i++) {
			answer = max(*max_element(board[i].begin(), board[i].end()), answer);
		}
		return;
	}

	if (direction == 0) {
		move_left(board);
	}
	else if (direction == 1) {
		move_right(board);
	}
	else if (direction == 2) {
		move_up(board);
	}
	else if (direction == 3) {
		move_down(board);
	}

	for (int i = 0; i < 4; i++) {
		dfs(board, i, depth + 1);
	}
}

int solution(vector<vector<int>>& board) {
	dfs(board, 0, 0);
	dfs(board, 1, 0);
	dfs(board, 2, 0);
	dfs(board, 3, 0);

	return answer;
}

int main() {
	int n;
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
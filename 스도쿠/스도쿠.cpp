#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void erase_rule_1(vector<int>& board, vector<int>& v, int row) {
	for (int i = 0; i < 9; i++) {
		auto it = find(v.begin(), v.end(), board[i * 9 + row]);
		if (it != v.end()) {
			v.erase(it);
		}
	}
}

void erase_rule_2(vector<int>& board, vector<int>& v, int col) {
	for (int i = 0; i < 9; i++) {
		auto it = find(v.begin(), v.end(), board[col * 9 + i]);
		if (it != v.end()) {
			v.erase(it);
		}
	}
}

void erase_rule_3(vector<int>& board, vector<int>& v, int row, int col) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			auto it = find(v.begin(), v.end(), board[((col / 3 * 3) + i) * 9 + ((row / 3 * 3) + j)]);
			if (it != v.end()) {
				v.erase(it);
			}
		}
	}
}

vector<vector<bool>> visit(81, vector<bool>(10));

void back_traking(vector<int> board) {
	if (accumulate(board.begin(), board.end(), 0) == 405) {
		for (int i = 0; i < 81; i++) {
			cout << board[i] << ' ';
			if ((i + 1) % 9 == 0) {
				cout << '\n';
			}
		}

		cout << endl;
		
		exit(0);
	}

	for (int i = 0; i < board.size(); i++) {
		if (board[i] == 0) {
			vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int x = i % 9, y = i / 9;
			erase_rule_1(board, v, x);
			erase_rule_2(board, v, y);
			erase_rule_3(board, v, x, y);
			if (!v.empty()) {
				for (int j = 0; j < v.size(); j++) {
					board[i] = v[j];
					back_traking(board);
				}

				break;
			}
			else {
				return;
			}
		}
	}
}

int main() {
	vector<int> board(81);
	for (int i = 0; i < 81; i++) {
		cin >> board[i];

		/*
		char ch = cin.get();
		if (ch == '\n') {
			ch = cin.get(); 
		}
		board[i] = ch - '0';
		*/
	}

	back_traking(board);

	return 0;
}

/*
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
*/
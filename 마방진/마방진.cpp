#include <iostream>
#include <vector>

using namespace std;

int get_row_sum(vector<vector<int>>& matrix, int y, int sum) {
	int s = 0;
	for (int i = 0; i < 3; i++) {
		s += matrix[y][i];
	}

	return (sum - s);
}

int get_col_sum(vector<vector<int>>& matrix, int x, int sum) {
	int s = 0;
	for (int i = 0; i < 3; i++) {
		s += matrix[i][x];
	}

	return (sum - s);
}

int get_diagonal_sum(vector<vector<int>>& matrix, int x, int y, int sum) {
	int s = 0;
	if (x != y) {
		for (int i = 0; i < 3; i++) {
			s += matrix[i][(2 - i)];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			s += matrix[i][i];
		}
	}

	return (sum - s);
}

bool is_safe(vector<vector<int>>& matrix, int sum) {
	int sum_diagonal_1 = matrix[0][0] + matrix[1][1] + matrix[2][2];
	int sum_diagonal_2 = matrix[0][2] + matrix[1][1] + matrix[2][0];
	if (sum != sum_diagonal_1 || sum != sum_diagonal_2) {
		return false;
	}

	for (int i = 0; i < 3; i++) {
		int sum_row = 0, sum_col = 0;
		for (int j = 0; j < 3; j++) {
			sum_row += matrix[i][j];
			sum_col += matrix[j][i];
		}

		if (sum != sum_row || sum != sum_col) {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	vector<vector<int>> matrix(3, vector<int>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> matrix[i][j];
		}
	}

	vector<vector<int>> copy_matrix = matrix;
	int min_x = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			min_x = max(
				max(min_x, abs(get_col_sum(matrix, j, 0))),
				max(get_row_sum(matrix,i,0), get_diagonal_sum(matrix,j,i,0))
			);
		}
	}

	while (!is_safe(copy_matrix, min_x - 1)) {
		copy_matrix = matrix;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (copy_matrix[i][j] == 0) {
					copy_matrix[i][j] = min(get_col_sum(matrix, j, min_x), get_row_sum(matrix, i, min_x));
					if (i == j || (2 - i) == j) {
						int diagonal = get_diagonal_sum(matrix, j, i, min_x);
						copy_matrix[i][j] = (copy_matrix[i][j] == 0) ? diagonal : min(copy_matrix[i][j], diagonal);
					}
				}
			}
		}

		++min_x;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << copy_matrix[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
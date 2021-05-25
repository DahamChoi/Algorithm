#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	string route;
	cin >> route;

	long long answer = 1, number = 1;
	long long pos_x = 0, pos_y = 0, left_value = 0, right_value = 1, up_value = 0, down_value = 2;
	for (int i = 0; i < route.length(); i++) {
		if (pos_x % 2 == 0 && pos_y % 2 == 0 || (pos_x % 2 == 1 && pos_y % 2 == 1)) {
			up_value = pos_x * 2 + 1;
			left_value = pos_x * 2;
			right_value = pos_y * 2 + 1;
			down_value = pos_y * 2 + 2;
		}
		else {
			up_value = pos_y * 2;
			left_value = pos_y * 2 + 1;
			right_value = pos_x * 2 + 2;
			down_value = pos_x * 2 + 1;
		}

		if (pos_x + pos_y + 1 >= N) {
			right_value -= ((pos_x + pos_y + 1) - N) * 2 + 1;
			down_value -= ((pos_x + pos_y + 1) - N) * 2 + 1;
		}

		if (pos_x + pos_y + 1 > N) {
			left_value -= ((pos_x + pos_y + 1) - N) * 2 - 1;
			up_value -= ((pos_x + pos_y + 1) - N) * 2 - 1;
		}

		if (route[i] == 'U') {
			--pos_y;
			number -= up_value;
		}
		else if (route[i] == 'D') {
			++pos_y;
			number += down_value;
		}
		else if (route[i] == 'L') {
			--pos_x;
			number -= left_value;
		}
		else if (route[i] == 'R') {
			++pos_x;
			number += right_value;
		}

		answer += number;
	}

	cout << answer;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N;	cin >> N;
	vector<int> sequence(N);
	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
	}

	vector<pair<int, int>> answer;
	while (true) {
		vector<pair<int, int>> primary_key;
		
	}

	if (answer.empty()) {
		cout << 'B';
	}
	else if (answer.size() == 1) {
		cout << (answer.front().first * sequence.back() + answer.front().second);
	}
	else {
		cout << 'A';
	}

	return 0;
}
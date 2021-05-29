#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long func(long long a, long long b, char o) {
	if (o == '+') {
		return a + b;
	}
	else if (o == '-') {
		return a - b;
	}
	else if (o == '*') {
		return a * b;
	}

	return -1;
}

long long get_operator_result(const vector<char>& operators, const vector<long long>& numbers, const vector<bool>& select) {
	vector<long long> operator_numbers = numbers;
	bool is_select_safe = true;
	for (int i = 0; i < select.size() - 1; i++) {
		if (select[i] && !select[i + 1]) {
			is_select_safe = false;
		}
		else if (select[i] && select[i + 1]) {
			++i;
		}
	}
	
	if (is_select_safe) {	
		for (int i = 0; i < select.size() - 1; i++) {
			if (select[i] && select[i + 1]) {
				operator_numbers[i] = func(numbers[i], numbers[i + 1], operators[i]);
				if (operators[i] != '*') {
					operator_numbers[i + 1] = 0;
				}
				else {
					operator_numbers[i + 1] = 1;
				}

				++i;
			}
		}

		for (int i = 0; i < operator_numbers.size() - 1; i++) {
			int value = func(operator_numbers[i], operator_numbers[i + 1], operators[i]);
			operator_numbers[i + 1] = value;
		}

		return operator_numbers.back();
	}
	else {
		return -INT_MAX;
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;

	vector<long long> numbers;
	vector<char> operators;
	string s;	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i % 2 == 0) {
			numbers.push_back(s[i] - '0');
		}
		else {
			operators.push_back(s[i]);
		}
	}

	if (numbers.size() == 1) {
		cout << numbers.front();
		return 0;
	}

	long long n = 2, answer = -INT_MAX;
	while (n <= numbers.size()) {
		vector<bool> cnd(numbers.size());
		for (int i = 0; i < n; i++) {
			cnd[i] = true;
		}

		do {
			answer = max(answer, get_operator_result(operators, numbers, cnd));
		} while (prev_permutation(cnd.begin(), cnd.end()));

		n += 2;
	}

	cout << answer;

	return 0;
}
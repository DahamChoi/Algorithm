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

long long get_operator_result(const vector<char>& operators, const vector<long long>& numbers, const vector<bool>& select, int select_cnt) {
	vector<long long> operator_numbers;
	vector<char> operator_operators;
	int cnt = 0;
	for (int i = 0; i < select.size() - 1; i++) {
		if (select[i] && select[i + 1]) {
			++i;	++cnt;
		}
	}
	
	bool is_select_safe = (cnt == (select_cnt / 2));
	if (is_select_safe) {
		for (int i = 0; i < select.size() - 1; i++) {
			if (select[i] && select[i + 1]) {
				operator_numbers.push_back(func(numbers[i], numbers[i + 1], operators[i]));
				if (i + 1 < operators.size()) {
					operator_operators.push_back(operators[i + 1]);
				}
				++i;
			}
			else {
				operator_numbers.push_back(numbers[i]);
				operator_operators.push_back(operators[i]);
			}
		}

		if (!select.back() && !numbers.empty()) {
			operator_numbers.push_back(numbers.back());
		}

		vector<long long> final_operator_numbers;
		vector<char> final_operator_operators;
		for (int i = 0; i < operator_numbers.size() - 1; i++) {
			if (operator_operators[i] == '*') {
				int result = operator_numbers[i];
				while (i < operator_operators.size() && operator_operators[i] == '*') {
					result *= operator_numbers[i + 1];
					++i;
				}
				final_operator_numbers.push_back(result);
				if (i < operator_operators.size()) {
					final_operator_operators.push_back(operator_operators[i]);
				}
			}
			else {
				final_operator_numbers.push_back(operator_numbers[i]);
				final_operator_operators.push_back(operator_operators[i]);
			}
		}

		if (!operator_operators.empty() && operator_operators.back() != '*' && !operator_numbers.empty()) {
			final_operator_numbers.push_back(operator_numbers.back());
		}

		for (int i = 0; i < final_operator_operators.size(); i++) {
			final_operator_numbers[i + 1] = func(final_operator_numbers[i], final_operator_numbers[i + 1], final_operator_operators[i]);
		}

		return final_operator_numbers.empty() ? operator_numbers.back() : final_operator_numbers.back();
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
			answer = max(answer, get_operator_result(operators, numbers, cnd, n));
		} while (prev_permutation(cnd.begin(), cnd.end()));

		n += 2;
	}

	cout << answer;

	return 0;
}
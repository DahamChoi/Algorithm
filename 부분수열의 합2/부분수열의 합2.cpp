#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(vector<int>& numberic, int s) {
	int half = numberic.size() / 2;
	int front_size = (1 << (numberic.size() - half)), back_size = (1 << half);
	long long answer = 0;
	vector<int> front(front_size), back(back_size);

	for (int i = 0; i < front_size; i++) {
		for (int j = 0; j < numberic.size() - half; j++) {
			if (i & (1 << j)) {
				front[i] += numberic[j];
			}
		}
	}

	for (int i = 0; i < back_size; i++) {
		for (int j = 0; j < numberic.size() - half; j++) {
			if (i & (1 << j)) {
				back[i] += numberic[j + (numberic.size() - half)];
			}
		}
	}

	sort(front.begin(), front.end());
	sort(back.begin(), back.end(), greater<int>());

	int front_idx = 0, back_idx = 0;
	while (front_idx < front_size && back_idx < back_size) {
		int select = front[front_idx] + back[back_idx];
		if (select == s) {
			long long cnt_front = 1, cnt_back = 1;
			++front_idx;	++back_idx;
			
			while (front_idx < front_size && front[front_idx] == front[front_idx - 1]) {
				++front_idx;
				++cnt_front;
			}

			while (back_idx < back_size && back[back_idx] == back[back_idx - 1]) {
				++back_idx;
				++cnt_back;
			}
			answer += (cnt_front * cnt_back);
		}
		else if (select < s) {
			++front_idx;
		}
		else if (select > s) {
			++back_idx;
		}
	}

	return (s == 0) ? answer - 1 : answer;
}

int main() {
	int n, s;
	cin >> n >> s;

	vector<int> numberic(n);
	for (int i = 0; i < n; i++) {
		cin >> numberic[i];
	}

	cout << solution(numberic, s);

	return 0;
}
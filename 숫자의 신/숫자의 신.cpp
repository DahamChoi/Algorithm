#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const string& left, const string& right) {
	int i;
	for (i = 0; i < left.length() && i < right.length(); i++) {
		if (left[i] != right[i]) {
			return left[i] > right[i];
		}
	}

	return left[i - 1] > right[i - 1];
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int K, N;
	cin >> K >> N;

	vector<string> weapon(K), sub_weapon(K);
	for (int i = 0; i < K; i++) {
		cin >> weapon[i];
		sub_weapon[i] = weapon[i];
	}

	sort(weapon.begin(), weapon.end(), [](const string& left, const string& right) {
		return compare(left, right);
		});

	sort(sub_weapon.begin(), sub_weapon.end(), [](const string& left, const string& right) {
		if (left.length() == right.length()) {
			return compare(left, right);
		}
		return left.length() > right.length();
		});

	string answer;	int i, weapon_idx, sub_weapon_cnt = 0;
	for (i = 0, weapon_idx = 0; i < N; i++) {
		if (weapon_idx < K && compare(weapon[weapon_idx], sub_weapon.front())) {
			answer += weapon[weapon_idx++];
		}
		else if(sub_weapon_cnt++) {
			answer += sub_weapon.front();
		}
	}

	cout << answer;

	return 0;
}

/*
4 4
9
8
71
72
*/
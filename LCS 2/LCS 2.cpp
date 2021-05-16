#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	unordered_map<char, int> m1, m2;
	for (int i = 0; i < s1.length(); i++) {
		++m1[s1[i]];
	}

	for (int i = 0; i < s2.length(); i++) {
		++m2[s2[i]];
	}

	string answer;
	for (auto& it : m1) {
		for (auto& it2 : m2) {
			if (it.first == it2.first) {
				for (int i = 0; i < it.second && i < it2.second; i++) {
					answer.push_back(it.first);
				}
			}
		}
	}

	cout << answer.length() << '\n';
	cout << answer;

	return 0;
}
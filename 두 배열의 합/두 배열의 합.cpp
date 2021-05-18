#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int>& a, vector<int>& b, int t) {
	long long answer = 0;

	vector<long long> memory_1, memory_2;
	for (auto i = 0; i < a.size(); i++) {
		long long sum = 0;
		for (auto j = i; j < a.size(); j++) {
			sum += a[j];
			memory_1.push_back(sum);
		}
	}

	for (auto i = 0; i < b.size(); i++) {
		long long sum = 0;
		for (int j = i; j < b.size(); j++) {
			sum += b[j];
			memory_2.push_back(sum);
		}
	}

	sort(memory_1.begin(), memory_1.end());
	sort(memory_2.begin(), memory_2.end());

	for (auto i = 0; i < memory_1.size(); i++) {
		answer += distance(lower_bound(memory_2.begin(), memory_2.end(), t - memory_1[i]), upper_bound(memory_2.begin(), memory_2.end(), t - memory_1[i]));
	}

	return answer;
}

int main() {
	int t;
	cin >> t;

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	cout << solution(a, b, t);

	return 0;
}
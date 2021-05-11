#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

double get_scalar(pair<int, int>& p) {
	return sqrt(pow(p.first, 2) + pow(p.second, 2));
}

double solution(vector<pair<int, int>>& v) {
	vector<bool> cnd(v.size());
	for (int i = 0; i < v.size() / 2; i++) {
		cnd[i] = true;
	}

	int ssx = 0, ssy = 0;
	for (int i = 0; i < v.size(); i++) {
		ssx += v[i].first;	ssy += v[i].second;
	}

	double answer = LLONG_MAX;
	do {
		int sx = 0, sy = 0;
		for (int i = 0; i < cnd.size(); i++) {
			if (cnd[i]) {
				sx += v[i].first;
				sy += v[i].second;
			}
		}

		answer = min(answer, sqrt(pow(ssx - sx - sx, 2) + pow(ssy - sy - sy, 2)));
	} while (prev_permutation(cnd.begin(), cnd.end()));

	return answer;
}

int main() {
	cout << fixed;
	cout.precision(12);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<pair<int, int>> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j].first >> v[j].second;
		}

		cout << solution(v) << "\n";
	}
	
	return 0;
}

/*

1
4
4 5
5 -5
-5 6
-5 -5

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ccw(const pair<long long, long long>& a, const pair<long long, long long>& b, const pair<long long, long long>& c) {
	return (a.first * b.second + b.first * c.second + c.first * a.second) -
		(a.second * b.first + b.second * c.first + c.second * a.first);
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;

	vector<pair<long long, long long>> points(N);
	for (int i = 0; i < N; i++) {
		cin >> points[i].first >> points[i].second;
	}

	sort(points.begin(), points.end(), [](const pair<long long, long long>& left, const pair<long long, long long>& right) {
		return (left.second == right.second) ? left.first < right.first : left.second < right.second;
		});

	sort(points.begin() + 1, points.end(), [&](const pair<long long, long long>& left, const pair<long long, long long>& right) {
		long long c = ccw(points.front(), left, right);
		return (c != 0) ? c > 0 : left.first + left.second < right.first + right.second;
		});

	vector<pair<long long, long long>> polygon;
	polygon.push_back(points.front());
	polygon.push_back(points[1]);

	for (int i = 2; i < N; i++) {
		while (polygon.size() > 1) {
			pair<long long, long long> ed = polygon.back();
			polygon.pop_back();
			pair<long long, long long> st = polygon.back();

			if (ccw(st, ed, points[i]) > 0) {
				polygon.push_back(ed);
				break;
			}
		}
		polygon.push_back(points[i]);
	}

	printf("%d\n", polygon.size());

	return 0;
}
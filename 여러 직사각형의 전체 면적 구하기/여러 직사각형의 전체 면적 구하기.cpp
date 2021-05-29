#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct square {
	int x, y1, y2, cnt;
	bool operator<(const square& right) {
		return (x == right.x) ? cnt < right.cnt : x < right.x;
	}
};

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	
	vector<square> squares;
	for (int i = 0; i < N; i++) {
		double x, y, width, height;
		cin >> x >> y >> width >> height;
		x *= 10;	y *= 10;	width *= 10;	height *= 10;
		squares.push_back({ (int)x, (int)y, (int)(y + height), 1 });
		squares.push_back({ (int)(x + width), (int)y, int(y + height), -1 });
	}

	sort(squares.begin(), squares.end());
	int answer = 0;	int lx = 0;
	vector<int> memory(20001);

	for (auto& it : squares) {
		int cnt = 0;
		for (int i = 0; i <= 20000; i++) {
			if (memory[i] > 0) {
				++cnt;
			}
		}

		answer += cnt * (it.x - lx);
		for (int i = it.y1 + 1; i <= it.y2; i++) {
			memory[i] = (it.cnt == 1) ? memory[i] + 1 : memory[i] - 1;
		}

		lx = it.x;
	}

	if (answer % 100 == 0) {
		printf("%d", answer / 100);
	}
	else {
		printf("%.2f", answer / 100.0);
	}

	return 0;
}
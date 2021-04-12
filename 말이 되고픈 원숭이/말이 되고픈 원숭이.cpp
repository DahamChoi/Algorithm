#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct monkey {
	int pos, knight, depth;
};

queue<monkey> q;
vector<int> map;

int main()
{
	int dx[8] = { -1, -2, -1, -2, 1, 2, 1, 2 };
	int dy[8] = { -2, -1, 2, 1, -2, -1, 2, 1 };
	int mdx[4] = { 1, 0, -1, 0 };
	int mdy[4] = { 0, 1, 0, -1 };

	int n, width, height, num;
	cin >> n;
	cin >> width >> height;

	for (int i = 0; i < width * height; i++) {
		cin >> num;
		map.push_back(num);
	}

	vector<bool[32]> visit(width * height);

	q.push({ 0, 0, 0 });
	visit[0][0] = true;

	while (!q.empty()) {
		monkey t = q.front();
		q.pop();

		int x = t.pos % width;
		int y = t.pos / width;

		if (t.pos == width * height - 1) {
			cout << t.depth;
			return 0;
		}

		if (t.knight < n) {
			for (int i = 0; i < 8; i++) {
				int ny = (y + dy[i]);
				int nx = (x + dx[i]);
				int ni = ny * width + nx;
				if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
					if (!visit[ni][t.knight + 1] && map[ni] == 0) {
						visit[ni][t.knight + 1] = true;
						q.push({ ni, t.knight + 1, t.depth + 1 });
					}
				}
			}
		}
		
		for (int i = 0; i < 4; i++) {
			int ny = (y + mdy[i]);
			int nx = (x + mdx[i]);
			int ni = ny * width + nx;
			if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
				if (!visit[ni][t.knight] && map[ni] == 0) {
					visit[ni][t.knight] = true;
					q.push({ ni, t.knight, t.depth + 1 });
				}
			}
		}
	}

	cout << -1;
	return 0;
}
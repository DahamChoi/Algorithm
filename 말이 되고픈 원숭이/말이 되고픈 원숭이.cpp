#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int dx[6] = { -2,-2,0,0,2,2 };
	int dy[6] = { -1,1,-2,2,-1,1 };

	int n, start, end, ix, iy;
	cin >> n;
	cin >> ix >> iy;
	start = iy * n + ix;
	cin >> ix >> iy;
	end = iy * n + ix;

	queue<int> q;
	vector<int> v(n * n);
	q.push(start);

	while (!q.empty())
	{
		int t = q.front();
		int x = t % n;
		int y = t / n;
		q.pop();

		if (t == end) {
			cout << v[t];
			return 0;
		}

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && v[ny * n + nx] == 0) {
				v[ny * n + nx] = v[y * n + x] + 1;
				q.push(ny * n + nx);
			}
		}
	}

	cout << "-1";
	return 0;
}
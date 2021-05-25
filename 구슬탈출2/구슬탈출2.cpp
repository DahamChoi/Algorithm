#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct queue_info {
	int rx{ 0 }, ry{ 0 }, bx{ 0 }, by{ 0 }, depth{ 0 };
};

queue_info move_left(const vector<string>& map, const queue_info& qi) {
	queue_info after = qi;
	while (map[after.by][after.bx - 1] != '#') {
		if (map[after.by][--after.bx] == 'O') {
			break;
		}
	}
	
	while (map[after.ry][after.rx - 1] != '#') {
		if (map[after.ry][--after.rx] == 'O') {
			break;
		}
	}

	if (after.bx == after.rx && after.by == after.ry && map[after.ry][after.rx] != 'O') {
		if (qi.bx < qi.rx) {
			++after.rx;
		}
		else {
			++after.bx;
		}
	}

	++after.depth;
	return after;
}

queue_info move_right(const vector<string>& map, const queue_info& qi) {
	queue_info after = qi;
	while (map[after.by][after.bx + 1] != '#') {
		if (map[after.by][++after.bx] == 'O') {
			break;
		}
	}

	while (map[after.ry][after.rx + 1] != '#') {
		if (map[after.ry][++after.rx] == 'O') {
			break;
		}
	}

	if (after.bx == after.rx && after.by == after.ry && map[after.ry][after.rx] != 'O') {
		if (qi.bx > qi.rx) {
			--after.rx;
		}
		else {
			--after.bx;
		}
	}

	++after.depth;
	return after;
}

queue_info move_up(const vector<string>& map, const queue_info& qi) {
	queue_info after = qi;
	while (map[after.by - 1][after.bx] != '#') {
		if (map[--after.by][after.bx] == 'O') {
			break;
		}
	}

	while (map[after.ry - 1][after.rx] != '#') {
		if (map[--after.ry][after.rx] == 'O') {
			break;
		}
	}

	if (after.bx == after.rx && after.by == after.ry && map[after.ry][after.rx] != 'O') {
		if (qi.by < qi.ry) {
			++after.ry;
		}
		else {
			++after.by;
		}
	}

	++after.depth;
	return after;
}

queue_info move_down(const vector<string>& map, const queue_info& qi) {
	queue_info after = qi;
	while (map[after.by + 1][after.bx] != '#') {
		if (map[++after.by][after.bx] == 'O') {
			break;
		}
	}

	while (map[after.ry + 1][after.rx] != '#') {
		if (map[++after.ry][after.rx] == 'O') {
			break;
		}
	}

	if (after.bx == after.rx && after.by == after.ry && map[after.ry][after.rx] != 'O') {
		if (qi.by > qi.ry) {
			--after.ry;
		}
		else {
			--after.by;
		}
	}

	++after.depth;
	return after;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int H, W;
	cin >> H >> W;

	vector<string> map(H);
	for (int i = 0; i < H; i++) {
		cin >> map[i];
	}

	queue<queue_info> q;
	queue_info first_position;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 'R') {
				first_position.rx = j;
				first_position.ry = i;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				first_position.bx = j;
				first_position.by = i;
				map[i][j] = '.';
			}
		}
	}
	q.push(first_position);

	int answer = 11;
	while (!q.empty()) {
		queue_info t = q.front();
		q.pop();

		if (map[t.by][t.bx] == 'O') {
			continue;
		}

		if (map[t.ry][t.rx] == 'O') {
			answer = min(answer, t.depth);
			continue;
		}

		if (t.depth < answer) {
			q.push(move_down(map, t));
			q.push(move_up(map, t));
			q.push(move_left(map, t));
			q.push(move_right(map, t));
		}
	}

	cout << ((answer == 11) ? -1 : answer);

	return 0;
}
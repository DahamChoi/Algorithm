#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

int a, b, c, d;
int answer = INT_MAX;

struct queue_info {
	int x, y, depth;
};

queue_info fill_a(queue_info& q) {
	return { a, q.y, q.depth + 1 };
}

queue_info fill_b(queue_info& q) {
	return { q.x, b, q.depth + 1 };
}

queue_info empty_x(queue_info& q) {
	return { 0, q.y, q.depth + 1 };
}

queue_info empty_y(queue_info& q) {
	return { q.x, 0, q.depth + 1 };
}

queue_info move_x_to_y(queue_info q) {
	if (q.y + q.x > b) {
		q.x -= (b - q.y);
		q.y = b;
	}
	else {
		q.y += q.x;
		q.x = 0;
	}

	++q.depth;

	return q;
}

queue_info move_y_to_x(queue_info q) {
	if (q.x + q.y > a) {
		q.y -= (a - q.x);
		q.x = a;
	}
	else {
		q.x += q.y;
		q.y = 0;
	}

	++q.depth;

	return q;
}

int main() {	
	cin >> a >> b >> c >> d;

	queue<queue_info> q;
	q.push({ 0,0,0 });

	map<pair<int, int>, bool> m;

	while (!q.empty()) {
		queue_info t = q.front();
		q.pop();

		if (t.depth >= answer) {
			continue;
		}

		if (t.x == c && t.y == d) {
			answer = min(t.depth, answer);
			continue;
		}

		if (m[{t.x, t.y}]) {
			continue;
		}

		m[{t.x, t.y}] = true;

		if (t.x != a && t.y > 0) {
			q.push(move_y_to_x(t));
		}

		if (t.y != b && t.x > 0) {
			q.push(move_x_to_y(t));
		}

		if (t.x != a) {
			q.push(fill_a(t));
		}

		if (t.y != b) {
			q.push(fill_b(t));
		}

		if (t.x > 0) {
			q.push(empty_x(t));
		}

		if (t.y > 0) {
			q.push(empty_y(t));
		}
	}

	cout << ((answer == INT_MAX) ? -1 : answer);

	return 0;
}
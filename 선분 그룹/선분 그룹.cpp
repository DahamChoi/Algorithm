#include <iostream>
#include <vector>

using namespace std;

struct vector2 {
	int x, y;

	bool operator==(const vector2& other) const {
		return (x == other.x && y == other.y);
	}
};

struct line {
	vector2 v1, v2;

	bool is_collision(const line& other) const {
		vector2 p1 = v1, p2 = v2, p3 = other.v1, p4 = other.v2;

		if (max(p1.x, p2.x) < min(p3.x, p4.x)) return false;
		if (min(p1.x, p2.x) > max(p3.x, p4.x)) return false;
		if (max(p1.y, p2.y) < min(p3.y, p4.y)) return false;
		if (min(p1.y, p2.y) > max(p3.y, p4.y)) return false;

		int sign1 = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
		int sign2 = (p2.x - p1.x) * (p4.y - p1.y) - (p4.x - p1.x) * (p2.y - p1.y);
		int sign3 = (p4.x - p3.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p4.y - p3.y);
		int sign4 = (p4.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p4.y - p3.y);

		if (sign1 == 0 && sign2 == 0 && sign3 == 0 && sign4 == 0) return true;

		return sign1 * sign2 <= 0 && sign3 * sign4 <= 0;
	}
};

void group_counter(vector<line>& lines, vector<bool>& visit, vector<int>& group, int index, int group_index) {
	visit[index] = true;

	for (int i = 0; i < lines.size(); i++) {
		if (!visit[i] && lines[index].is_collision(lines[i])) {
			++group[group_index];
			group_counter(lines, visit, group, i, group_index);
		}
	}
}

vector<int> solution(vector<line>& lines) {
	vector<bool> visit(lines.size());
	vector<int> group(lines.size());

	for (int i = 0; i < lines.size(); i++) {
		if (!visit[i]) {
			++group[i];
			group_counter(lines, visit, group, i, i);
		}
	}

	int group_cnt = 0, max_group_cnt = 0;
	for (int i = 0; i < group.size(); i++) {
		if (group[i] > 0) {
			++group_cnt;
			max_group_cnt = max(max_group_cnt, group[i]);
		}
	}

	return { group_cnt, max_group_cnt };
}

int main() {
	int n;
	scanf("%d", &n);

	vector<line> lines(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &lines[i].v1.x, &lines[i].v1.y, &lines[i].v2.x, &lines[i].v2.y);
	}

	vector<int> answer = solution(lines);
	cout << answer[0] << "\n" << answer[1] << "\n";

	return 0;
}

/*
10
1 1 2 3
2 1 0 0
1 0 1 1
3 3 4 4
4 4 5 5
5 5 6 6
6 6 5 5
7 7 8 8
9 9 10 10
11 12 12 13
*/
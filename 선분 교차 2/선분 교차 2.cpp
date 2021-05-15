#include <iostream>

using namespace std;

struct vector2 {
	double x, y;
};

struct line {
	vector2 v1, v2;

	bool is_collision(const line& other) const {
		vector2 p1 = v1, p2 = v2, p3 = other.v1, p4 = other.v2;

		if (max(p1.x, p2.x) < min(p3.x, p4.x)) return false;
		if (min(p1.x, p2.x) > max(p3.x, p4.x)) return false;
		if (max(p1.y, p2.y) < min(p3.y, p4.y)) return false;
		if (min(p1.y, p2.y) > max(p3.y, p4.y)) return false;

		double sign1 = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
		double sign2 = (p2.x - p1.x) * (p4.y - p1.y) - (p4.x - p1.x) * (p2.y - p1.y);
		double sign3 = (p4.x - p3.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p4.y - p3.y);
		double sign4 = (p4.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p4.y - p3.y);

		if (sign1 == 0 && sign2 == 0 && sign3 == 0 && sign4 == 0) return true;

		return sign1 * sign2 <= 0 && sign3 * sign4 <= 0;
	}
};

int main() {
	line l1, l2;

	cin >> l1.v1.x >> l1.v1.y >> l1.v2.x >> l1.v2.y;
	cin >> l2.v1.x >> l2.v1.y >> l2.v2.x >> l2.v2.y;

	if (l1.is_collision(l2)) {
		cout << "1";
	}
	else {
		cout << "0";
	}

	return 0;
}
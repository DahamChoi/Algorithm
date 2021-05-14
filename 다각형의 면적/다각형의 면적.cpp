#include <iostream>
#include <vector>

using namespace std;

struct point {
    int x{ 0 }, y{ 0 };
};

double solution(vector<point>& points) {
    long long a = 0, b = 0;
    points.push_back(points.front());

    for (int i = 1; i < points.size(); i++) {
        a += (long long)points[i - 1].x * points[i].y;
        b += (long long)points[i - 1].y * points[i].x;
    }

    return (abs(a - b) / 2.0);
}

int main() {
    int n;

    scanf("%d", &n);

    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    cout.setf(ios::fixed);
    cout.precision(1);
    cout << solution(points);

    return 0;
}

/*
3
2 4
3 -8
1 2
*/
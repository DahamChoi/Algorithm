#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, num;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &num);
            pq.push(num);
            if (i >= 1) {
                pq.pop();
            }
        }
    }

    cout << pq.top();
}
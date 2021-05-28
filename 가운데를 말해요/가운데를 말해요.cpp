#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	
	int N;	cin >> N;
	priority_queue<int, vector<int>, less<>> pq1;
	priority_queue<int, vector<int>, greater<>> pq2;

	for (int i = 0; i < N; i++) {
		int num;	cin >> num;

		if (pq1.size() <= pq2.size()) {
			pq1.push(num);
		}
		else {
			pq2.push(num);
		}

		if (!pq1.empty() && !pq2.empty() && pq1.top() > pq2.top()) {
			int t1 = pq1.top(), t2 = pq2.top();
			pq1.pop();	pq2.pop();
			pq1.push(t2);	pq2.push(t1);
		}

		cout << pq1.top() << '\n';
	}

	return 0;
}
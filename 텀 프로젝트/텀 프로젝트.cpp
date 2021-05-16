#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int>& students) {
	int answer = 0, n = students.size();
	vector<bool> visit(n);
	
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			int next = students[i] - 1, depth = 0;
			vector<int> history;
			history.push_back(i);
			visit[i] = true;
			while (!visit[next]) {
				history.push_back(next);
				visit[next] = true;
				next = students[next] - 1;
			}
			history.push_back(next);

			for (int j = 0; j < history.size(); j++) {
				if (history[j] == next) {
					break;
				}

				++answer;
			}
		}
	}

	return answer;
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);

		vector<int> students(n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &students[j]);
		}

		cout << solution(students) << '\n';
	}

	return 0;
}

/*
1
4
2 3 4 3
*/
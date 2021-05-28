#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;

	vector<long long> times(M);
	for (int i = 0; i < M; i++) {
		cin >> times[i];
	}

    if (N <= M) {
        cout << N;
        return 0;
    }

    N -= M;

    int answer = 1;
    double time_per_people = 0.0;
    for (int i = 0; i < times.size(); i++) {
        time_per_people += (1.0 / times[i]);
    }

    long long time_limit = (N / time_per_people);

    long long sum = 0;
    vector<long long> counter(times.size());
    for (int i = 0; i < counter.size(); i++) {
        counter[i] = times[i] - (time_limit % times[i]);
        sum += (time_limit / times[i]);
    }

    while (sum < N) {
        for (int i = 0; i < counter.size(); i++) {
            if (--counter[i] <= 0) {
                if (++sum >= N) {
                    answer = i + 1;
                    break;
                }

                counter[i] = times[i];
            }
        }
    }

    cout << answer;

	return 0;
}
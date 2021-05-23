#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void k_slice(int k, vector<int>& lock) {
	while (k-- > 0) {
		int front = lock.front();
		for (int i = 0; i < lock.size() - 1; i++) {
			lock[i] = lock[i + 1];
		}
		lock.back() = front;
	}
}

void pq_swap(int p, int q, vector<int>& lock) {
	for (int i = p - 1, j = q - 1; i < j; i++, j--) {
		int temp = lock[i];
		lock[i] = lock[j];
		lock[j] = temp;
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> lock(N);
	for (int i = 0; i < N; i++) {
		cin >> lock[i];
	}

	/*
	int N = 10;
	vector<int> lock(N);
	for (int i = 0; i < N; i++) {
		lock[i] = i + 1;
	}

	srand((unsigned)time(0));
	int first_k_slice = rand() % N + 1;
	int third_k_slice = rand() % N + 1;
	int swap_p = rand() % N + 1;
	int swap_q = (swap_p != N) ? swap_p + (rand() % (N - swap_p) + 1) : (rand() % N + 1);
	k_slice(first_k_slice, lock);
	pq_swap(swap_p, swap_q, lock);
	k_slice(third_k_slice, lock);
	for (int i = 0; i < N; i++) {
		cout << lock[i] << ' ';
	}
	cout << endl;
	cout << first_k_slice << ' ' << swap_p << '~' << swap_q << ' ' << third_k_slice << endl;
	*/

	int first_k = 0, second_k = 0;
	int p = N - 1, q = 0;

	vector<bool> is_ascending(N);
	for (int i = 1; i < N - 1; i++) {
		is_ascending[i] = (lock[i] - lock[i - 1] == 1) || (lock[i + 1] - lock[i] == 1) || (lock[i] == 1 && lock[i - 1] == N) || (lock[i] == N && lock[i + 1] == 1);
	}
	is_ascending.front() = (lock.front() - lock.back() == 1) || (lock[1] - lock[0] == 1) || (lock.front() == 1 && lock.back() == N) || (lock[1] == 1 && lock[0] == N);
	is_ascending.back() = (lock.back() - lock[lock.size() - 2] == 1) || (lock.front() - lock.back() == 1) || (lock.back() == 1 && lock[lock.size() - 2] == N) || (lock.front() == 1 && lock.back() == N);

	auto it = find(is_ascending.begin(), is_ascending.end(), false);
	if (it == is_ascending.begin()) {
		for (auto iter = it; iter != is_ascending.end() && (*iter) == false; iter++) {
			++q;
		}
		--q;

		for (auto iter = (is_ascending.end() - 1); iter != is_ascending.begin() && (*iter) == false; iter--) {
			--p;
		}
		++p;
	}
	else {
		q = p = distance(is_ascending.begin(), it);
		for (auto iter = it; iter != is_ascending.end() && (*iter) == false; iter++) {
			++q;
		}
		--q;
	}

	/*
	auto it_true = find(is_ascending.begin(), is_ascending.end(), true);
	auto original_index = lock[distance(is_ascending.begin(), it_true)] - 1;
	auto lock_index = distance(is_ascending.begin(), it_true);
	auto dist = (original_index > lock_index) ? (original_index - lock_index) : (N - (lock_index - original_index));
	auto third_left_slice = (p > q) ? (N - p) : (dist / 2);
	auto first_left_slice = dist - third_left_slice;
	*/

	int third_left_slice = 0, first_left_slice = 0;

	while (p > q) {
		++third_left_slice;
		k_slice(1, lock);
		--p;	--q;
		p = (p < 0) ? (N - 1) : p;
		q = (q < 0) ? (N - 1) : q;
	}

	vector<int> origin_lock(N);
	for (int i = 0; i < N; i++) {
		origin_lock[i] = i + 1;
	}

	pq_swap(p + 1, q + 1, lock);
	while (origin_lock != lock) {
		++first_left_slice;
		k_slice(1, lock);
	}

	cout << (N - first_left_slice) << endl;
	cout << (p + 1) << ' ' << (q + 1) << endl;
	cout << (N - third_left_slice) << endl;

	return 0;
}

/*
10
1 10 6 7 8 9 5 4 3 2
*/
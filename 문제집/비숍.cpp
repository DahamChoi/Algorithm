#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int answer = 0;
pair<int, int> dist[4] = { {-1,1},{-1,-1},{1,1},{1,-1} };

void search(vector<int> board, int index, int n, int sum) {
    int xx = index % n;
    int yy = index / n;
    for (int i = yy * n; i < (yy + 1) * n; i++) {
        if (board[i] == 1) {
            ++sum;
            for (int k = 0; k < 4; k++) {
                int nx = (i % n);
                int ny = (i / n);
                while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    board[ny * n + nx] = 0;
                    nx += dist[k].first;
                    ny += dist[k].second;
                }
            }
        }
    }

    answer = max(sum, answer);
    for (int i = 0; i < n * n; i++) {
        if (board[i] == 1) {
            search(board, i, n, sum);
        }
    }
}

void search_2(vector<int> board, int index, int n, int sum) {
    int xx = index % n;
    int yy = index / n;
    for (int i = xx; i < n * n; i += n) {
        if (board[i] == 1) {
            ++sum;
            for (int k = 0; k < 4; k++) {
                int nx = (i % n);
                int ny = (i / n);
                while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    board[ny * n + nx] = 0;
                    nx += dist[k].first;
                    ny += dist[k].second;
                }
            }
        }
    }

    answer = max(sum, answer);
    for (int i = 0; i < n * n; i++) {
        if (board[i] == 1) {
            search(board, i, n, sum);
        }
    }
}

int solution(vector<int>& board, int n) {
    for (int i = 0; i < n * n; i++) {
        if (board[i] == 1) {
            search(board, i, n, 0);
        }
    }

    for (int i = 0; i < n * n; i++) {
        if (board[i] == 1) {
            search_2(board, i, n, 0);
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> board(n * n);
    for (int i = 0; i < n * n; i++) {
        cin >> board[i];
    }

    cout << solution(board, n);

    return 0;
}

/*
10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
*/
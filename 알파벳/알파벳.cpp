#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int answer = 0, c, r;
vector<vector<int>> board(21, vector<int>(21));
vector<bool> history(26);

void dfs(int x, int y, int depth) {
    answer = max(answer, depth);

    history[board[y][x]] = true;

    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < c && ny >= 0 && ny < r && !history[board[ny][nx]]) {
            dfs(nx, ny, depth + 1);
        }
    }

    history[board[y][x]] = false;
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        
        for (int j = 0; j < c; j++) {
            board[i][j] = s[j] - 'A';
        }
    }

    history[board.front().front()] = true;

    dfs(0, 0, 1);

    cout << answer;

    return 0;
}
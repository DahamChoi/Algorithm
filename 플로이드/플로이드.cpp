#include <iostream>
#include <vector>
using namespace std;

void floyd(vector<vector<int>>& arr) {
    int n = arr.size() - 1;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 10000000));
    for (int i = 0; i <= n; i++) {
        arr[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        arr[a][b] = c;
        arr[b][a] = c;
    }

    floyd(arr);

    int min_index = 1;
    int min_time = 100000000;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += arr[i][j];
        }
        
        if (sum < min_time) {
            min_index = i;
            min_time = sum;
        }
    }

    cout << min_index;
}
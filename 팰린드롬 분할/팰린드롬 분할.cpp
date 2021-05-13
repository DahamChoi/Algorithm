#include <iostream>
#include <string>
#include <vector>

using namespace std;

int is_palindrom(string& s, int index) {
    int answer = 0;

    for (int j = s.length() - 1; j >= index; j--) {
        int left = index, right = j;
        while (left + 1 < right - 1 && s[left] == s[right]) {
            ++left;
            --right;
        }

        if (s[left] == s[right]) {
            answer = max(answer, (j - index) + 1);
        }
    }

    return answer;
}

int solution(string& s) {
    vector<int> dp(s.length() + 1, 0);

    for (int i = 0; i < dp.size() - 1; i++) {
        int p = is_palindrom(s, i);
        if (dp[i + 1] > 0) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }
        else {
            dp[i + 1] = dp[i] + 1;
        }

        if (dp[i + p] > 0) {
            dp[i + p] = min(dp[i + p], dp[i] + 1);
        }
        else {
            dp[i + p] = dp[i] + 1;
        }
    }

    return dp.back();
}

int main() {
    string s;
    cin >> s;

    cout << solution(s);

    return 0;
}
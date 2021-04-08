#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(vector<int>& v, int m)
{
    int answer = 0;
    int s = m - 1;
    while (true)
    {
        if (s > v.size() - 1)
        {
            if(v.size() % m != 0)
                answer += v[s - m + 1];
            return answer;
        }
        else
        {
            answer += v[s] * 2;
            s += m;
        }
    }
}

int main()
{
    int n, m;
    int answer = 0;
    
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    std::sort(v.begin(), v.end());

    vector<int> v1, v2;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it > 0)
        {
            v1 = { v.begin(), it };
            v2 = { it, v.end() };
            break;
        }
    }

    for (auto it = v1.begin(); it != v1.end(); it++)
        (*it) *= -1;
    sort(v1.begin(), v1.end());

    if (v1.back() > v2.back())
    {
        answer += f(v2, m);
        answer += f(v1, m);
    }
    else
    {
        answer += f(v1, m);
        answer += f(v2, m);
    }

    cout << answer;
}
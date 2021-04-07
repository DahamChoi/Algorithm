#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

void f(const string& str, vector<int>& m)
{
    static unordered_map<char, int> a = { {'C',0},{'H',1},{'O',2} };

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (str.size() == 1 || (str[i + 1] >= 'A' && str[i + 1] <= 'Z'))
                m[a[str[i]]] += 1;
            else
            {
                m[a[str[i]]] += str[i + 1] - '0';
            }
        }
    }
}

vector<int> solution(const string& str)
{
    vector<int> m1(3), m2(3), m3(3);
    vector<int> pre{ 1,2,3,4,5,6,7,8,9,10 };

    int n1 = str.find('+');
    int n2 = str.find('=');

    f(str.substr(0, n1), m1);
    f(str.substr(n1 + 1, 1), m2);
    f(str.substr(n2 + 1, str.size() - n2), m3);

    do {
        if (pre[0] * m1[0] + pre[1] * m2[0] == pre[2] * m3[0]
            && pre[0] * m1[1] + pre[1] * m2[1] == pre[2] * m3[1]
            && pre[0] * m1[2] + pre[1] * m2[2] == pre[2] * m3[2])
        {
            return { pre[0], pre[1], pre[2] };
        }
    } while (next_permutation(pre.begin(), pre.end()));

    return { 1, 1, 1 };
}

int main()
{
    vector<int> v = solution("HO3H2+O=H2O2O2");
    for (auto it : v)
    {
        cout << it << endl;
    }
}
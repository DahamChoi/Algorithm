#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s1;
	cin >> s1;

	string s2 = s1;
	sort(s2.begin(), s2.end());

	int n = 0;
	int s = 0, e = s1.length() - 1;

	while (n < s1.length() - 1)
	{
		for (int i = s; i <= e; i++)
		{
			if (s1[i] == s2[n])
			{
				reverse(s1.begin() + s, s1.begin() + i + 1);
				++s;
				e = i - 1;
			}
		}

		++n;
	}

	cout << s1 << endl;
}
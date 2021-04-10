#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int m;
	int l;
	vector<int> v;

	cin >> n;
	cin >> m;
	cin >> l;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	
	v.insert(v.begin(), 0);
	v.push_back(l);

	vector<pair<float, float>> pv;
	for (int i = 0; i < v.size() - 1; i++)
		pv.push_back(make_pair(v[i + 1] - v[i], 1));

	while (m-- > 0)
	{
		sort(pv.begin(), pv.end());

		float first = pv[pv.size() - 1].first;
		float second = pv[pv.size() - 1].second;
		pv[pv.size() - 1] = make_pair((first * second) / (second + 1.f), second + 1.f);
	}

	cout << ceil(pv[pv.size() - 2].first);
}
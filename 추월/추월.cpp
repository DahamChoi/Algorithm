#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(int num, vector<string> push_cars, vector<string> pop_cars) {
	int answer = 0;
	int push_cars_index = 0, pop_cars_index = 0;
	while (push_cars_index < push_cars.size() && pop_cars_index < pop_cars.size()) {
		if (push_cars[push_cars_index] != pop_cars[pop_cars_index]) {
			push_cars.erase(find(push_cars.begin(), push_cars.end(), pop_cars[pop_cars_index]));
			++pop_cars_index;
			++answer;
		}
		else {
			++pop_cars_index;
			++push_cars_index;
		}
	}

	return answer;
}

int main()
{
	int num;
	cin >> num;
	vector<string> push_cars(num);
	vector<string> pop_cars(num);

	for (int i = 0; i < num; i++) {
		cin >> push_cars[i];
	}

	for (int i = 0; i < num; i++) {
		cin >> pop_cars[i];
	}

	cout << solution(num, push_cars, pop_cars);
}
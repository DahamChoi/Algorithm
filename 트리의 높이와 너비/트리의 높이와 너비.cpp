#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
	node* left,* right;
	int depth{ 0 }, index{ 0 };
};

void get_node_cnt(node* noe, int& result) {
	if (noe->left) {
		++result;
		get_node_cnt(noe->left, result);
	}

	if (noe->right) {
		++result;
		get_node_cnt(noe->right, result);
	}
}

void set_depth(node* noe, int depth) {
	noe->depth = depth;

	if (noe->left) {
		set_depth(noe->left, depth + 1);
	}

	if (noe->right) {
		set_depth(noe->right, depth + 1);
	}
}

void set_index(node* noe, int parent_index, int direction) {
	int left_value = 0, right_value = 0;

	if (noe->left) {
		get_node_cnt(noe->left, left_value);
		++left_value;
	}

	if (noe->right) {
		get_node_cnt(noe->right, right_value);
		++right_value;
	}

	if (direction == -1) {
		noe->index = parent_index - right_value - 1;
	} 
	else {
		noe->index = parent_index + left_value + 1;
	}

	if (noe->left) {
		set_index(noe->left, noe->index, -1);
	}

	if (noe->right) {
		set_index(noe->right, noe->index, 1);
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N;	cin >> N;
	vector<node*> nodes(N + 1);
	for (int i = 0; i < N + 1; i++) {
		nodes[i] = new node{ nullptr, nullptr };
	}

	vector<bool> visit(N + 1);
	for (int i = 0; i < N; i++) {
		int index, left, right;		cin >> index >> left >> right;
		nodes[index]->left = (left != -1) ? nodes[left] : nullptr;
		nodes[index]->right = (right != -1) ? nodes[right] : nullptr;

		visit[left != -1 ? left : 0] = true;
		visit[right != -1 ? right : 0] = true;
	}

	int root_index = 0;
	for (int i = 1; i < N + 1; i++) {
		if (!visit[i]) {
			root_index = i;
			break;
		}
	}

	// root node?
	set_depth(nodes[root_index], 1);

	if (nodes[root_index]->left) {
		int result = 1;
		get_node_cnt(nodes[root_index]->left, result);
		set_index(nodes[root_index]->left, result, -1);
	}
	
	if (nodes[root_index]->right) {
		int result = 1;
		get_node_cnt(nodes[root_index]->right, result);
		set_index(nodes[root_index]->right, N - result - 1, 1);
	}

	map<int, vector<int>> um;
	for (int i = 1; i < N + 1; i++) {
		um[nodes[i]->depth].push_back(nodes[i]->index);
	}

	int answer_width = 1, answer_level = 1;
	for (auto& it : um) {
		if (it.second.size() > 1) {
			sort(it.second.begin(), it.second.end());
			if ((it.second.back() - it.second.front() + 1) > answer_width) {
				answer_level = it.first;
				answer_width = it.second.back() - it.second.front() + 1;
			}
		}
	}

	printf("%d %d\n", answer_level, answer_width);

	return 0;
}
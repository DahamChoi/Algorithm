#include <iostream>
#include <vector>

using namespace std;

struct node {
	int key, priority, size;
	node* left, * right;

	node(const int& key) : key{ key }, priority{ rand() }, size(1), left{ NULL }, right{ NULL } {}
	void set_left(node* left) { this->left = left;		calc_size(); }
	void set_right(node* right) { this->right = right;  calc_size(); }

	void calc_size() {
		size = 1;
		if (left)	size += left->size;
		if (right)	size += right->size;
	}
};

pair<node*, node*> split(node* root, int key) {
	if (root == NULL)	return { NULL,NULL };
	if (root->key < key) {
		pair<node*, node*> rs = split(root->right, key);
		root->set_right(rs.first);
		return { root, rs.second };
	}
	else {
		pair<node*, node*> ls = split(root->left, key);
		root->set_left(ls.second);
		return { ls.first, root };
	}
}

node* insert(node* root, node* noe) {
	if (root == NULL)	return noe;
	if (root->priority < noe->priority) {
		pair<node*, node*> splitted = split(root, noe->key);
		noe->set_left(splitted.first);
		noe->set_right(splitted.second);
		return noe;
	}
	else if (noe->key < root->key) {
		root->set_left(insert(root->left, noe));
	}
	else {
		root->set_right(insert(root->right, noe));
	}
	return root;
}

node* merge(node* a, node* b) {
	if (a == NULL)	return b;
	if (b == NULL)	return a;
	if (a->priority < b->priority) {
		b->set_left(merge(a, b->left));
		return b;
	}
	else {
		a->set_right(merge(a->right, b));
		return a;
	}
}

node* erase(node* root, int key) {
	if (root == NULL)	return root;
	if (root->key == key) {
		node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	else if (key < root->key) {
		root->set_left(erase(root->left, key));
	}
	else {
		root->set_right(erase(root->right, key));
	}
	return root;
}

void upper_key(node* root, int key, int& answer) {
	if (root == NULL)	return;
	if (root->key > key) {
		answer = root->key;
		upper_key(root->left, key, answer);
	}
	else {
		upper_key(root->right, key, answer);
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	node* root = NULL;
	for (int i = 0; i < M; i++) {
		int card;
		cin >> card;
		root = insert(root, new node(card));
	}

	vector<int> pay_cards(K);
	for (int i = 0; i < K; i++) {
		cin >> pay_cards[i];
	}

	for (int i = 0; i < pay_cards.size(); i++) {
		int key;
		upper_key(root, pay_cards[i], key);
		cout << key << '\n';
		root = erase(root, key);
	}

	return 0;
}
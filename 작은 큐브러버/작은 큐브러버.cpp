#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int index;
    char top, left, right, r_top{ 'X' }, r_left{ 'Y' }, r_right{ 'Z' };

    void rotate_1() {
        int tmp = r_right;
        r_right = left;
        left = right;
        right = r_left;
        r_left = tmp;
    }

    void rotate_2() {
        int tmp = top;
        top = left;
        left = r_top;
        r_top = r_left;
        r_left = top;
    }

    void rotate_3() {
        int tmp = top;
        top = right;
        right = r_top;
        r_top = r_right;
        r_right = tmp;
    }
};

bool is_safe(vector<node>& v) {
    return(
        (v[0].top == v[0].left && v[0].left == v[0].right) &&
        (v[1].top == v[1].left && v[1].top == v[1].r_right) &&
        (v[2].top == v[2].r_left && v[2].r_left == v[2].r_right) &&
        (v[3].top == v[3].right && v[3].right == v[3].r_left) &&
        (v[4].r_top == v[4].left && v[4].left == v[4].right) &&
        (v[5].r_top == v[5].left && v[5].left == v[5].r_right) &&
        (v[4].r_top == v[4].r_left && v[4].left == v[4].r_right) &&
        (v[5].r_top == v[5].left && v[5].left == v[5].r_right)
        );
}

struct compare {
    bool operator()(const node& left, const node& right) {
        return left.index < right.index;
    }
};

void func(vector<node>& nodes, int index) {
    if (index >= nodes.size()) {
        if (is_safe(nodes)) {
            cout << "YES";
            exit(0);
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < i; l++) {
                    nodes[index].rotate_1();
                }

                for (int l = 0; l < j; l++) {
                    nodes[index].rotate_2();
                }

                for (int l = 0; l < k; l++) {
                    nodes[index].rotate_3();
                }

                func(nodes, index + 1);
            }
        }
    }
}

int main() {
    vector<node> nodes(8);
    for (int i = 0; i < 8; i++) {
        cin >> nodes[i].top >> nodes[i].left >> nodes[i].right;
        nodes[i].index = i;
    }

    func(nodes, 0);

    cout << "NO";
    return 0;
}
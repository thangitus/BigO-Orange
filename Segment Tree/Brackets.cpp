#include <bits/stdc++.h>


using namespace std;
struct Node {
    int sum, minSum;
};

void buildTree(vector<int> &nums, vector<Node> &tree, int left, int right, int index) {
    if (left == right) {
        tree[index].sum = tree[index].minSum = nums[left];
        return;
    }
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    buildTree(nums, tree, left, mid, childLeft);
    buildTree(nums, tree, mid + 1, right, childRight);
    tree[index].sum = tree[childLeft].sum + tree[childRight].sum;
    tree[index].minSum = min(tree[childLeft].minSum, tree[childLeft].sum + tree[childRight].minSum);
}

void update(vector<Node> &tree, int left, int right, int index, int pos) {
    if (pos < left || pos > right) return;
    if (left == right) {
        tree[index].sum = tree[index].minSum = -tree[index].sum;
        return;
    }
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    if (pos <= mid) update(tree, left, mid, childLeft, pos);
    else update(tree, mid + 1, right, childRight, pos);
    tree[index].sum = tree[childLeft].sum + tree[childRight].sum;
    tree[index].minSum = min(tree[childLeft].minSum, tree[childLeft].sum + tree[childRight].minSum);
}

int main() {
    for (int k = 1; k <= 10; k++) {
        cout << "Test " << k << ":\n";
        int n, m, op;
        char c;
        cin >> n;
        int h = ceil(log2(n)), size = pow(2, h + 1) - 1;
        vector<int> nums(n);
        vector<Node> tree(size);
        for (int i = 0; i < n; i++) {
            cin >> c;
            nums[i] = c == '(' ? 1 : -1;
        }
        buildTree(nums, tree, 0, n - 1, 0);
        cin >> m;

        while (m--) {
            cin >> op;
            if (op == 0) {
                bool result = tree[0].sum == 0 && tree[0].minSum == 0;
                if (result) cout << "YES\n";
                else cout << "NO\n";
            } else update(tree, 0, n - 1, 0, op - 1);
        }
    }
}

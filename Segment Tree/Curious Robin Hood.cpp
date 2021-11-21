#include <bits/stdc++.h>


using namespace std;

void buildTree(vector<int> &nums, vector<int> &tree, int left, int right, int index) {
    if (left == right) {
        tree[index] = nums[left];
        return;
    }
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    buildTree(nums, tree, left, mid, childLeft);
    buildTree(nums, tree, mid + 1, right, childRight);
    tree[index] = tree[childLeft] + tree[childRight];
}

int sumRange(vector<int> &tree, int left, int right, int from, int to, int index) {
    if (from <= left && right <= to)
        return tree[index];
    if (from > right || to < left)
        return 0;
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    return sumRange(tree, left, mid, from, to, childLeft) +
           sumRange(tree, mid + 1, right, from, to, childRight);
}

void update(vector<int> &tree, vector<int> &nums, int left, int right, int index, int pos, int value) {
    if (pos < left || pos > right) return;
    if (left == right) {
        nums[pos] = value;
        tree[index] = value;
        return;
    }
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    if (pos <= mid) update(tree, nums, left, mid, childLeft, pos, value);
    else update(tree, nums, mid + 1, right, childRight, pos, value);
    tree[index] = tree[childLeft] + tree[childRight];
}

int main() {
    int t, n, q, option, from, to, value, pos;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> n >> q;
        int h = ceil(log2(n)), size = pow(2, h + 1) - 1;
        vector<int> nums(n), tree(size);
        for (int &num: nums) cin >> num;
        buildTree(nums, tree, 0, n - 1, 0);
        cout << "Case " << k << ":\n";
        while (q--) {
            cin >> option;
            if (option == 1) {
                cin >> pos;
                cout << nums[pos] << endl;
                update(tree, nums, 0, n - 1, 0, pos, 0);
            } else if (option == 2) {
                cin >> pos >> value;
                update(tree, nums, 0, n - 1, 0, pos, nums[pos] + value);
            } else {
                cin >> from >> to;
                cout << sumRange(tree, 0, n - 1, from, to, 0) << endl;
            }
        }
    }
}
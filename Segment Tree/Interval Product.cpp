#include <bits/stdc++.h>


using namespace std;

void buildTree(vector<int> &nums, vector<int> &tree, int left, int right, int index) {
    if (left == right) {
        tree[index] = nums[left] < 0 ? -1 : nums[left] > 0 ? 1 : 0;
        return;
    }
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    buildTree(nums, tree, left, mid, childLeft);
    buildTree(nums, tree, mid + 1, right, childRight);
    tree[index] = tree[childLeft] * tree[childRight];
}

int productRange(vector<int> &tree, int left, int right, int from, int to, int index) {
    if (from <= left && right <= to)
        return tree[index];
    if (from > right || to < left)
        return 1;
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    return productRange(tree, left, mid, from, to, childLeft) *
           productRange(tree, mid + 1, right, from, to, childRight);
}

void update(vector<int> &tree, vector<int> &nums, int left, int right, int index, int pos, int value) {
    if (pos < left || pos > right) return;
    if (left == right) {
        nums[pos] = tree[index] = value < 0 ? -1 : value > 0 ? 1 : 0;
        return;
    }
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    if (pos <= mid) update(tree, nums, left, mid, childLeft, pos, value);
    else update(tree, nums, mid + 1, right, childRight, pos, value);
    tree[index] = tree[childLeft] * tree[childRight];
}

int main() {
    int n, k, pos, value, from, to;
    char query;
    while (cin >> n >> k) {
        int h = ceil(log2(n)), size = pow(2, h + 1) - 1;
        vector<int> nums(n), tree(size, 1);
        for (int &num: nums) cin >> num;
        buildTree(nums, tree, 0, n - 1, 0);
        while (k--) {
            cin >> query;
            if (query == 'C') {
                cin >> pos >> value;
                update(tree, nums, 0, n - 1, 0, pos - 1, value);
            } else {
                cin >> from >> to;
                int product = productRange(tree, 0, n - 1, from - 1, to - 1, 0);
                if (product < 0) cout << '-';
                else if (product > 0) cout << '+';
                else cout << '0';
            }
        }
        cout << endl;
    }
}
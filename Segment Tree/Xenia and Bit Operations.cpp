#include <bits/stdc++.h>


using namespace std;

void buildTree(vector<int> &nums, vector<int> &tree, int left, int right, int index, bool isXor) {
    if (left == right) {
        tree[index] = nums[left];
        return;
    }
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    buildTree(nums, tree, left, mid, childLeft, !isXor);
    buildTree(nums, tree, mid + 1, right, childRight, !isXor);
    if (isXor) tree[index] = tree[childLeft] ^ tree[childRight];
    else tree[index] = tree[childLeft] | tree[childRight];
}

void update(vector<int> &tree, vector<int> &nums, int left, int right, int index, int pos, int value, bool isXor) {
    if (pos < left || pos > right) return;
    if (left == right) {
        nums[pos] = value;
        tree[index] = value;
        return;
    }
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    if (pos <= mid) update(tree, nums, left, mid, childLeft, pos, value, !isXor);
    else update(tree, nums, mid + 1, right, childRight, pos, value, !isXor);

    if (isXor) tree[index] = tree[childLeft] ^ tree[childRight];
    else tree[index] = tree[childLeft] | tree[childRight];
}

int main() {
    int n, q, pos, value;
    cin >> n >> q;
    n = 1 << n;
    int h = ceil(log2(n)), size = pow(2, h + 1) - 1;
    vector<int> nums(n), tree(size);
    for (int &num: nums) cin >> num;
    bool isXor = h % 2 == 0;
    buildTree(nums, tree, 0, n - 1, 0, isXor);
    while (q--) {
        cin >> pos >> value;
        update(tree, nums, 0, n - 1, 0, pos - 1, value, isXor);
        cout << tree[0] << endl;
    }
}
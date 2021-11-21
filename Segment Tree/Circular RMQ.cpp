#include <bits/stdc++.h>


using namespace std;
vector<int> token;

void buildTree(vector<int> &nums, vector<int> &tree, int left, int right, int index) {
    if (left == right) {
        tree[index] = nums[left];
        return;
    }
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    buildTree(nums, tree, left, mid, childLeft);
    buildTree(nums, tree, mid + 1, right, childRight);
    tree[index] = min(tree[childLeft], tree[childRight]);
}

void updateLazy(vector<int> &tree, vector<int> &lazy, int left, int right, int from, int to, int index, int value) {
    if (left > right) return;
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    if (lazy[index]) {
        tree[index] += lazy[index];
        if (left != right) {
            lazy[childLeft] += lazy[index];
            lazy[childRight] += lazy[index];
        }
        lazy[index] = 0;
    }

    //No overlap
    if (from > right || to < left) return;

    //Total overlap
    if (left >= from && to >= right) {
        tree[index] += value;
        if (left != right) {
            lazy[childLeft] += value;
            lazy[childRight] += value;
        }
        return;
    }

    //partial overlap
    updateLazy(tree, lazy, left, mid, from, to, childLeft, value);
    updateLazy(tree, lazy, mid + 1, right, from, to, childRight, value);
    tree[index] = min(tree[childLeft], tree[childRight]);
}

int minRange(vector<int> &tree, vector<int> &lazy, int left, int right, int from, int to, int index) {
    if (left > right) return INT_MAX;
    int mid = (right - left) / 2 + left, childLeft = 2 * index + 1, childRight = 2 * index + 2;
    if (lazy[index]) {
        tree[index] += lazy[index];
        if (left != right) {
            lazy[childLeft] += lazy[index];
            lazy[childRight] += lazy[index];
        }
        lazy[index] = 0;
    }

    if (from > right || to < left) return INT_MAX;
    if (left >= from && to >= right) return tree[index];
    return min(minRange(tree, lazy, left, mid, from, to, childLeft),
               minRange(tree, lazy, mid + 1, right, from, to, childRight));
}

int main() {
    int n, m, v, result, from, to, left, right;
    string str;

    cin >> n;
    int h = ceil(log2(n)), size = pow(2, h + 1) - 1;
    vector<int> nums(n), tree(size), lazy(size);
    for (int &num: nums) cin >> num;
    buildTree(nums, tree, 0, n - 1, 0);
    cin >> m;
    getline(cin, str);
    while (m--) {
        getline(cin, str);
        stringstream ss(str);
        token.clear();
        while (ss >> v) token.push_back(v);
        from = token[0], to = token[1];
        if (token.size() == 3) {
            if (from > to) {
                updateLazy(tree, lazy, 0, n - 1, 0, to, 0, token[2]);
                updateLazy(tree, lazy, 0, n - 1, from, n - 1, 0, token[2]);
            } else updateLazy(tree, lazy, 0, n - 1, from, to, 0, token[2]);
        } else {
            if (from > to) {
                left = minRange(tree, lazy, 0, n - 1, 0, to, 0);
                right = minRange(tree, lazy, 0, n - 1, from, n - 1, 0);
                result = min(left, right);
            } else result = minRange(tree, lazy, 0, n - 1, from, to, 0);
            cout << result << endl;
        }
    }
}
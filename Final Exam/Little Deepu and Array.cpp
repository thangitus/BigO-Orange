#include <bits/stdc++.h>

using namespace std;
int n, m, x;
const int MAX = 1e5 + 5;
int arr[MAX];

void buildTree(vector<int> &tree, int left, int right, int index) {
    if (left > right) return;
    if (left == right) {
        tree[index] = arr[left];
        return;
    }
    buildTree(tree, left, (left + right) / 2, index * 2);
    buildTree(tree, (left + right) / 2 + 1, right, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

void
updateTree(vector<int> &tree, vector<int> &lazy, int left, int right, int index) {
    if (left > right || left >= n || right < 0) return;
    if (lazy[index] != 0) {
        tree[index] += lazy[index];
        if (left != right) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    if (tree[index] > x) {
        tree[index]--;
        if (left != right) {
            lazy[index * 2]--;
            lazy[index * 2 + 1]--;
        }
        return;
    }

    if (left == right) return;
    updateTree(tree, lazy, left, (right + left) / 2, index * 2);
    updateTree(tree, lazy, (left + right) / 2 + 1, right, index * 2 + 1);
    tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
}

int queryTree(vector<int> &tree, vector<int> &lazy, int left, int right, int beg, int end, int index) {
    if (left > right || left > end || right < beg) return 1e9;
    if (lazy[index] != 0) {
        tree[index] += lazy[index];
        if (left != right) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    if (left >= beg && end <= right) return tree[index];
    int q1 = queryTree(tree, lazy, left, (left + right) / 2, beg, end, index * 2);
    int q2 = queryTree(tree, lazy, (left + right) / 2 + 1, right, beg, end, index * 2 + 1);
    int res = min(q1, q2);
    return res;
}

int main() {
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = make_pair(x, i + 1);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        arr[i] = a[i].first;
    }
    int h = (int) ceil(log2(n)), size = pow(2, h + 1) - 1;
    vector<int> segmentTree(size, 1e9);
    vector<int> lazy(size, 0);
    buildTree(segmentTree, 0, n - 1, 1);
    cin >> m;
    while (m--) {
        cin >> x;
        updateTree(segmentTree, lazy, 0, n - 1, 1);
    }
    for (int i = 0; i < n; i++) {
        a[i].first = queryTree(segmentTree, lazy, 0, n - 1, i, i, 1);
        swap(a[i].first, a[i].second);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        cout << a[i].second << " ";

    cout << endl;
    return 0;
}
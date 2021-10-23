#include <bits/stdc++.h>


using namespace std;
typedef long long long2;

long2 merge(vector<int> &left, vector<int> &right, long2 l, long2 mid, long2 r) {
    long2 result = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (i == j) j++;
        if (right[j] >= left[i]) i++;
        else {
            while (j < r && left[i] > right[j + 1]) j++;
            result += j - mid;
            i++;
        }
    }
    inplace_merge(left.begin() + l, left.begin() + mid + 1, left.begin() + r + 1);
    inplace_merge(right.begin() + l, right.begin() + mid + 1, right.begin() + r + 1);
    return result;
}

long2 mergeSort(vector<int> &left, vector<int> &right, long2 l, long2 r) {
    if (l == r) return 0;
    long2 result = 0, mid = (r + l) / 2;
    result += mergeSort(left, right, l, mid);
    result += mergeSort(left, right, mid + 1, r);
    result += merge(left, right, l, mid, r);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n), left(n), right(n);
    unordered_map<int, int> count;
    for (int &num:nums) cin >> num;
    for (int i = 0; i < n; i++) {
        count[nums[i]]++;
        left[i] = count[nums[i]];
    }
    count.clear();
    for (int i = n - 1; i >= 0; i--) {
        count[nums[i]]++;
        right[i] = count[nums[i]];
    }
    long2 result = mergeSort(left, right, 0, n - 1);
    cout << result << endl;
}

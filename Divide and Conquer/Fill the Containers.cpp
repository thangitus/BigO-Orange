#include <bits/stdc++.h>


using namespace std;
vector<int> nums;
int n, m;

bool check(int value) {
    int count = 0, curSum = 0;
    for (int i = 0; i < n; i++) {
        curSum += nums[i];
        if (curSum > value) {
            count++;
            curSum = nums[i];
        }
    }
    if (curSum > 0) count++;
    return count <= m;
}

int binarySearch(int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            right = mid - 1;
        } else left = mid + 1;
    }
    return left;
}

int main() {
    while (cin >> n) {
        cin >> m;
        nums.clear(), nums.resize(n);
        int left = INT_MAX, right = 0, maxVal = INT_MIN;
        for (int &num:nums) {
            cin >> num;
            right += num;
            left = min(left, num);
            maxVal = max(maxVal, num);
        }
        cout << max(binarySearch(left, right), maxVal) << endl;
    }
}
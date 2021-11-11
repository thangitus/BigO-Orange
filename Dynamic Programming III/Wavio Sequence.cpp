#include <bits/stdc++.h>

using namespace std;

vector<int> lis(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n), sub;
    sub.push_back(nums[0]);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] > sub.back()) {
            sub.push_back(nums[i]);
            dp[i] = sub.size();
        } else {
            auto index = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
            sub[index] = nums[i];
            dp[i] = index + 1;
        }
    }
    return dp;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int &num:nums) cin >> num;
        auto left = lis(nums);
        reverse(nums.begin(), nums.end());
        auto right = lis(nums);
        reverse(right.begin(), right.end());
        int result = 0;
        for (int i = 0; i < n; i++)
            result = max(result, min(left[i], right[i]) * 2 - 1);

        cout << result << endl;
    }
}
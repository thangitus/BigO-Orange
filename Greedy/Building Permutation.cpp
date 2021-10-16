#include <bits/stdc++.h>


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &num:nums) cin >> num;
    sort(nums.begin(), nums.end());
    long long result = 0;
    for (int i = 1; i <= n; i++)
        result += abs(i - nums[i - 1]);
    cout << result;
};
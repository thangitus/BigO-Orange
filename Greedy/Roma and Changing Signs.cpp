#include <bits/stdc++.h>


using namespace std;

bool compare(int &a, int &b) {
    return abs(a) < abs(b);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &num:nums) cin >> num;
    sort(nums.begin(), nums.end(), compare);
    int i = n - 1;
    while (i >= 0 && k) {
        if (nums[i] < 0) {
            nums[i] *= -1;
            k--;
        }
        i--;
    }
    while (k) {
        nums[0] *= -1;
        k--;
    }
    long long result = 0;
    for (int &num:nums) result += num;
    cout << result << endl;
}
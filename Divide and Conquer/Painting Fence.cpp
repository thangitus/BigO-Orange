#include <bits/stdc++.h>


using namespace std;
vector<int> nums;
int n;

int dfs(int left, int right, int prev) {
    if (left > right) return 0;
    int minIndex = left;
    for (int i = left; i <= right; i++)
        if (nums[i] < nums[minIndex]) minIndex = i;
    int paintMin = nums[minIndex] - prev;
    int leftSide = dfs(left, minIndex - 1, nums[minIndex]);
    int rightSide = dfs(minIndex + 1, right, nums[minIndex]);
    return min(right - left + 1, leftSide + paintMin + rightSide);
}

int main() {
    cin >> n;
    nums.resize(n);
    for (int &num:nums) cin >> num;
    int result = dfs(0, n - 1, 0);
    cout << result << endl;
}
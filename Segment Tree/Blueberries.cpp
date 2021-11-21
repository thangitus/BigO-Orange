#include <bits/stdc++.h>


using namespace std;
int dp[1001][1001];
int n, k, nums[1001];

int solve(int i, int sum) {
    if (i >= n) return 0;
    if (dp[i][sum] == -1) {
        int curr = 0, next;
        if (nums[i] + sum <= k)
            curr = nums[i] + solve(i + 2, nums[i] + sum);
        next = solve(i + 1, sum);
        dp[i][sum] = max(curr, next);
    }
    return dp[i][sum];
}

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> nums[i];
        int result = solve(0, 0);
        cout << "Scenario #" << cs << ": " << result << endl;
    }
}
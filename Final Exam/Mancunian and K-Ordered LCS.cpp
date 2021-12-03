#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 2001, MAX_K = 6;
int dp[MAX_N][MAX_N][MAX_K], nums1[MAX_N], nums2[MAX_N];

int lcs(int n, int m, int k) {
    if (k < 0) return -1e7;
    if (n <= 0 || m <= 0) return 0;
    int &result = dp[n][m][k];
    if (result == -1) {
        result = max(lcs(n - 1, m, k), lcs(n, m - 1, k));
        if (nums1[n - 1] == nums2[m - 1])
            result = max(result, lcs(n - 1, m - 1, k) + 1);
        result = max(result, lcs(n - 1, m - 1, k - 1) + 1);
    }
    return result;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < m; i++) cin >> nums2[i];
    cout << lcs(n, m, k) << endl;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int cs, n, w;
    cin >> cs;
    while (cs--) {
        cin >> n >> w;
        int c[n], p[n], t[n];
        vector<vector<int>> dp(n + 1, vector<int>(w + 1));
        for (int i = 0; i < n; i++)
            cin >> c[i] >> p[i] >> t[i];
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= w; j++) {
                if (t[i - 1] > j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i - 1]] + c[i - 1] * p[i - 1]);
            }
        cout << dp[n][w] << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;


int main() {
    int t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int dp[n + 1][m + 1][k + 1];
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                for (int l = 0; l <= k; l++) {
                    if (i == 0 || j == 0 || l == 0)
                        dp[i][j][l] = 0;
                    else if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[l - 1])
                        dp[i][j][l] = dp[i - 1][j - 1][l - 1] + 1;
                    else dp[i][j][l] = max({dp[i - 1][j][l], dp[i][j - 1][l], dp[i][j][l - 1]});
                }
        cout << dp[n][m][k] << endl;
    }
}
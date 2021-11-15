#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    while (true) {
        cin >> k;
        if (!k) return 0;
        string s, t;
        cin >> s >> t;
        int n = s.length(), m = t.length(), dp[n + 1][m + 1], count[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = count[i][j] = 0;
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    count[i][j] = s[i - 1] == t[j - 1] ? count[i - 1][j - 1] + 1 : 0;
                    for (int c = k; c <= count[i][j]; c++)
                        dp[i][j] = max(dp[i][j], dp[i - c][j - c] + c);
                }
            }
        cout << dp[n][m] << endl;
    }
}
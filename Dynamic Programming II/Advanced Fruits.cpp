#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1) {
        cin >> s2;
        int n = s1.length(), m = s2.length();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        int i = n, j = m, len = n + m - dp[n][m];
        string result;
        result.resize(len);
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result[len - 1] = s1[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) result[len - 1] = s1[--i];
            else result[len - 1] = s2[--j];
            len--;
        }
        while (i > 0) result[--len] = s1[--i];
        while (j > 0) result[--len] = s2[--j];
        cout << result << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;
typedef long long long2;

bool readInput(vector<string> &result) {
    string line;
    while (cin >> line) {
        if (line == "#") return true;
        result.push_back(line);
    }
    return false;
}

int main() {
    while (true) {
        vector<string> s1, s2;
        if (!readInput(s1)) return 0;
        readInput(s2);
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        int i = n, j = m, len = dp[n][m];
        vector<string> result(len);
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result[len - 1] = s1[i - 1];
                i--, j--, len--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
        for (const auto &s:result) cout << s << ' ';
        cout << endl;
    }
}
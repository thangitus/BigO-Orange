#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, w, n;
    while (cin >> t) {
        cin >> w >> n;
        int d[n], v[n], c[n];
        for (int i = 0; i < n; i++) {
            cin >> d[i] >> v[i];
            c[i] = 3 * w * d[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(t + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= t; j++) {
                dp[i][j] = dp[i - 1][j];
                int index = j - c[i - 1];
                if (index >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][index] + v[i - 1]);
            }
        vector<int> path;
        for (int i = n; i > 0; i--) {
            if (dp[i][t] != dp[i - 1][t]) {
                path.push_back(i);
                t -= c[i - 1];
            }
        }
        reverse(path.begin(), path.end());
        cout << dp[n].back() << endl;
        cout << path.size() << endl;
        for (int i: path)
            cout << d[i - 1] << ' ' << v[i - 1] << endl;
        cout << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, m, s;
    cin >> t;
    while (t--) {
        cin >> m >> s;
        int coins[m][2], target = s * s, result = 1e9;

        //dp[i][j] minimum coin to get sum equal i and j
        vector<vector<int>> dp(s + 1, vector<int>(s + 1, 1e9));
        for (auto &coin: coins)
            cin >> coin[0] >> coin[1];
        dp[0][0] = 0;
        for (auto coin: coins) {
            int x = coin[0], y = coin[1];
            for (int i = x; i * i + y * y <= target; i++)
                for (int j = y; j * j + i * i <= target; j++)
                    dp[i][j] = min(dp[i][j], dp[i - x][j - y] + 1);
        }
        for (int i = 0; i <= s; i++)
            for (int j = 0; j <= s; j++)
                if (i * i + j * j == target)
                    result = min(result, dp[i][j]);
        if (result != 1e9) cout << result << endl;
        else cout << "not possible\n";
    }
}
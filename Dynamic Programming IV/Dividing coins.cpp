#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int coins[n], sum = 0;
        for (int &coin:coins) {
            cin >> coin;
            sum += coin;
        }
        int avg = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(avg + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= avg; j++) {
                dp[i][j] = dp[i - 1][j];
                int index = j - coins[i - 1];
                if (index >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][index] + coins[i - 1]);
            }
        cout << sum - 2 * dp[n][avg] << endl;
    }
}
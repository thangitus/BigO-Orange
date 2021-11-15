#include <bits/stdc++.h>

using namespace std;
const int MAX = 2e4;

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> dp(MAX, 1e9);
        int coins[m];
        for (int &coin:coins) cin >> coin;
        dp[0] = 0;
        for (int coin:coins)
            for (int i = MAX - coin; i >= 0; i--)
                dp[i + coin] = min(dp[i + coin], dp[i] + 1);

        for (int i = n;; i++)
            if (dp[i] != 1e9) {
                cout << i << ' ' << dp[i] << endl;
                break;
            }
    }
}
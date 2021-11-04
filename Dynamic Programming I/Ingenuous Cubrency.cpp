#include <bits/stdc++.h>

using namespace std;
typedef long long long2;

int main() {
    vector<long2> coins, dp(10000);
    for (int i = 1; i <= 21; i++)
        coins.push_back(i * i * i);
    dp[0] = 1;
    for (auto coin:coins)
        for (auto i = coin; i < 10000; i++)
            dp[i] += dp[i - coin];

    int n;
    while (cin >> n)
        cout << dp[n] << endl;

}
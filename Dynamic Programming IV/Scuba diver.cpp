#include <bits/stdc++.h>

using namespace std;

int main() {
    int cs, oxi, nitro, n;
    cin >> cs;
    while (cs--) {
        cin >> oxi >> nitro >> n;
        int t[n], a[n], w[n];
        for (int i = 0; i < n; i++)
            cin >> t[i] >> a[i] >> w[i];
        int dp[n + 1][oxi + 1][nitro + 1];
        for (int o = 0; o <= oxi; o++)
            for (int ni = 0; ni <= nitro; ni++)
                dp[0][o][ni] = 1e9;
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int o = 0; o <= oxi; o++) {
                for (int ni = 0; ni <= nitro; ni++) {
                    dp[i][o][ni] = dp[i - 1][o][ni];
                    int ti = t[i - 1], ai = a[i - 1], wi = w[i - 1];
                    dp[i][o][ni] = min(dp[i][o][ni], dp[i - 1][max(0, o - ti)][max(0, ni - ai)] + wi);
                }
            }
        }
        cout << dp[n][oxi][nitro] << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;
typedef long long long2;

int main() {
    string s;
    do {
        cin >> s;
        if (s == "0") break;
        auto n = s.length();
        vector<long2> dp(n + 1);
        dp[0] = 1, dp[1] = s[0] != '0';
        for (int i = 1; i < n; i++) {
            if (s[i] != '0') dp[i + 1] = dp[i];
            int num = stoi(s.substr(i - 1, 2));
            if (num < 27 && num > 9) dp[i + 1] += dp[i - 1];
        }
        cout << dp[n] << endl;
    } while (true);
}
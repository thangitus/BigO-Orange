#include <bits/stdc++.h>

using namespace std;
typedef long long long2;

void readInput(vector<int> &nums) {
    int num;
    do {
        cin >> num;
        if (!num) return;
        nums.push_back(num);
    } while (true);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> agne;
        vector<vector<int>> toms;
        readInput(agne);
        do {
            vector<int> tmp;
            readInput(tmp);
            if (tmp.empty()) break;
            toms.push_back(tmp);
        } while (true);

        int result = 0, n = agne.size();
        for (auto tom:toms) {
            int m = tom.size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1));
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= m; j++) {
                    if (i == 0 || j == 0) dp[i][j] = 0;
                    else if (agne[i - 1] == tom[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            result = max(result, dp[n][m]);
        }
        cout << result << endl;
    }
}
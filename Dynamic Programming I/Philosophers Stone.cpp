#include <bits/stdc++.h>

using namespace std;
typedef long long long2;

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (auto &row:matrix)
            for (int &num:row) cin >> num;
        vector<int> dp = matrix[0];
        for (int i = 1; i < n; i++) {
            vector<int> tmp(m);
            for (int j = 0; j < m; j++) {
                int maxVal = dp[j];
                if (j > 0) maxVal = max(maxVal, dp[j - 1]);
                if (j < m - 1) maxVal = max(maxVal, dp[j + 1]);
                tmp[j] = maxVal + matrix[i][j];
            }
            dp = tmp;
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}

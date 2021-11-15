#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1005;
const int MAX_L = 4005;

struct Item {
    int length, value;
};

long long dp[MAX_N][MAX_L][3];
Item arr[MAX_N];

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cout << "Case #" << k << ": ";
        int n, L;
        long long res = -1;
        cin >> n >> L;
        L = L * 2;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].length >> arr[i].value;
            res = max(res, 1LL * arr[i].value);
        }

        for (auto &numItem: dp)
            for (auto &len: numItem)
                for (auto &option: len)
                    option = 0;


        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= L; j++)
                for (int c = 0; c < 3; c++) {
                    dp[i][j][c] = dp[i - 1][j][c];
                    if (j >= 2 * arr[i].length)
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j - 2 * arr[i].length][c] + 1LL * arr[i].value);


                    if (j >= arr[i].length && c > 0)
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j - arr[i].length][c - 1] + 1LL * arr[i].value);

                }

        for (int c = 0; c <= 2; c++)
            res = max(res, dp[n][L][c]);
        cout << res << endl;
    }
    return 0;
}
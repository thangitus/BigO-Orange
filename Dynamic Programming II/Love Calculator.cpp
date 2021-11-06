#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        string s1, s2;
        cin >> s1;
        cin >> s2;
        int m = s1.length(), n = s2.length();
        long scs[m + 1][n + 1], numWays[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                scs[i][j] = numWays[i][j] = 0;
                if (i == 0 || j == 0) {
                    scs[i][j] = i + j;
                    numWays[i][j] = 1;
                } else if (s1[i - 1] == s2[j - 1]) {
                    scs[i][j] = scs[i - 1][j - 1] + 1;
                    numWays[i][j] = numWays[i - 1][j - 1];
                } else {
                    scs[i][j] = min(scs[i - 1][j], scs[i][j - 1]) + 1;
                    if (scs[i][j] == scs[i - 1][j] + 1)
                        numWays[i][j] += numWays[i - 1][j];
                    if (scs[i][j] == scs[i][j - 1] + 1)
                        numWays[i][j] += numWays[i][j - 1];
                }
            }
        cout << "Case " << k << ": " << scs[m][n] << " " << numWays[m][n] << endl;
    }
    return 0;
}
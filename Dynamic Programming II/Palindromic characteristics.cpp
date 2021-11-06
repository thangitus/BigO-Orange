#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    s = " " + s;
    int n = s.length();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n));
    vector<vector<int>> dp(n, vector<int>(n));
    vector<int> count(n);
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
        dp[i][i] = 1;
        if (i < n - 1)
            isPalindrome[i + 1][i] = true;
    }
    for (int i = n - 1; i > 0; i--)
        for (int j = i; j < n; j++) {
            isPalindrome[i][j] = j == i || (isPalindrome[i + 1][j - 1] && s[i] == s[j]);
            if (isPalindrome[i][j]) {
                int t = (i + j - 1) / 2;
                dp[i][j] = dp[i][t] + 1;
                count[dp[i][j]]++;
            }
        }
    for (int i = n - 2; i >= 1; i--)
        count[i] += count[i + 1];
    for (int i = 1; i < n; i++)
        cout << count[i] << ' ';
}
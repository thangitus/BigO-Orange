#include <bits/stdc++.h>

using namespace std;
typedef long long long2;
unordered_map<long2, long2> memo;

long2 dp(long2 n) {
    if (n < 3) return n;
    if (memo[n]) return memo[n];
    memo[n] = max(n, dp(n / 2) + dp(n / 3) + dp(n / 4));
    return memo[n];
}

int main() {
    int n;
    while (cin >> n)
        cout << dp(n) << endl;
}
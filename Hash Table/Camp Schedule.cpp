#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
int cnt[2], cntNeed[2];
typedef long long int long2;

int main() {
    string s, t, result;
    cin >> s >> t;
    long2 m = t.length(), left[m + 1], right[m + 1], base = 31, p = 1, pos = 0;
    for (char c:s) cnt[c - '0']++;
    for (char c:t) cnt[c - '0']--;
    if (cnt[0] < 0 || cnt[1] < 0) {
        cout << s;
        return 0;
    }

    left[0] = 0, right[m] = 0;
    for (int i = 1; i <= m; i++)
        left[i] = (t[i - 1] + base * left[i - 1]) % MOD;
    for (int i = m - 1; i >= 0; i--) {
        right[i] = (t[i] * p + right[i + 1]) % MOD;
        p = (1LL * p * base) % MOD;
    }

    for (int i = 1; i < m; i++)
        if (left[i] == right[m - i])
            pos = i;
    result = t;
    t = t.substr(pos);
    for (char c:t) cntNeed[c - '0']++;

    while (cnt[0] >= cntNeed[0] && cnt[1] >= cntNeed[1]) {
        cnt[0] -= cntNeed[0];
        cnt[1] -= cntNeed[1];
        result += t;
    }
    while (cnt[1]--) result += '1';
    while (cnt[0]--) result += '0';
    cout << result << endl;
}

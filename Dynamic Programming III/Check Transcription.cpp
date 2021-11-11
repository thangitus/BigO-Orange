#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
const int K = 41;
const int MAX = 1e6 + 5;
long long h[MAX], pw[MAX], len[2], cnt[2], g[2], f[2];

long long get(int l, int r) {
    return (h[r] - 1LL * h[l - 1] * pw[r - l + 1] % P + P) % P;
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for (int i = 1; i <= n; i++)
        cnt[s[i] - '0']++;
    pw[0] = 1;
    for (int i = 1; i <= m; i++) {
        pw[i] = (1LL * pw[i - 1] * K) % P;
        h[i] = (1LL * h[i - 1] * K + t[i] - 'a' + 1) % P;
    }
    int result = 0;
    for (int i = 1;; i++) {
        f[0] = f[1] = 1;
        if (cnt[0] * i >= m) break;
        if ((m - cnt[0] * i) % cnt[1]) continue;
        len[0] = i;
        len[1] = (m - cnt[0] * i) / cnt[1];
        for (int l = 1, k = 1; k <= n; k++) {
            int cur = s[k] - '0';
            if (f[cur])
                g[cur] = get(l, l + len[cur] - 1), f[cur] = 0;
            else if (g[cur] != get(l, l + len[cur] - 1))
                break;
            if (!f[0] && !f[1] && g[0] == g[1])
                break;
            if (k == n) result++;
            l += len[cur];
        }
    }
    cout << result << '\n';
    return 0;
}
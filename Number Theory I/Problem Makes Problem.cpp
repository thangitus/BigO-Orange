#include <bits/stdc++.h>


using namespace std;
#define MAX 2000002
#define MOD 1000000007
typedef long long long2;
long2 fac[MAX]{1};

long2 extEuclid(long2 b, long2 m) {
    long2 q, r;
    long2 x[]{1, 0, 1}, y[]{0, 1, 0};
    long2 mod = m;
    while (m) {
        q = b / m, r = b % m;
        x[2] = x[0] - q * x[1];
        y[2] = y[0] - q * y[1];
        x[0] = x[1], y[0] = y[1];
        x[1] = x[2], y[1] = y[2];
        b = m, m = r;
    }
    return (x[0] + mod) % mod;
}

long2 combination(long2 n, long2 k) {
    long2 inverse = extEuclid(fac[n - k] * fac[k], MOD);
    return fac[n] * inverse % MOD;
}

int main() {
    int t, n, k;
    cin >> t;

    for (int i = 1; i < MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    for (int i = 1; i <= t; i++) {
        cin >> n >> k;
        int result = combination(n + k - 1, k - 1);
        cout << "Case " << i << ": " << result << endl;
    }
}


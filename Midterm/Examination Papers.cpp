#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        long long result = 1, a = 2;
        while (n) {
            if (n % 2)
                result = (result * a) % MOD;
            n /= 2;
            a = (a * a) % MOD;
        }
        cout << result - 1 << endl;
    }
}
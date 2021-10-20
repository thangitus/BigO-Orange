#include <bits/stdc++.h>


using namespace std;

pair<int, int> extEuclid(int b, int m) {
    int q, r;
    int x[]{1, 0, 1}, y[]{0, 1, 0};
    while (m) {
        q = b / m, r = b % m;
        x[2] = x[0] - q * x[1];
        y[2] = y[0] - q * y[1];
        x[0] = x[1], y[0] = y[1];
        x[1] = x[2], y[1] = y[2];
        b = m, m = r;
    }
    return {x[0], y[0]};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, k;
        cin >> c >> k;
        a = c / k, b = ceil(c * 1.0 / k);
        if (a == b) {
            cout << k << ' ' << 0 << endl;
            continue;
        }
        auto result = extEuclid(a, b);
        cout << result.first * c << " " << result.second * c << endl;
    }
}

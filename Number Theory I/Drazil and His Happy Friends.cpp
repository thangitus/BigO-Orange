#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m, a, b, num;
    cin >> n >> m;
    vector<bool> boy(n), girl(m);
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> num;
        boy[num] = true;
    }
    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> num;
        girl[num] = true;
    }
    int lcm = (n * m) / __gcd(n, m);
    for (int i = 0; i <= 2 * lcm; i++) {
        bool isHappy = boy[i % n] || girl[i % m];
        boy[i % n] = isHappy;
        girl[i % m] = isHappy;
    }
    for (int i = 0; i < max(n, m); i++) {
        if (!boy[i % n] || !girl[i % m]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
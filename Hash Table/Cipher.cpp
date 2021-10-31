#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, prev = 0;
    string s;
    cin >> n >> k >> s;
    vector<int> bit(n);
    for (int i = s.length() - 1; i >= k - 1; i--) {
        int cur = s[i] == '1';
        bit[i - k + 1] = cur ^ prev;
        prev ^= bit[i - k + 1];
        if (i <= s.length() - k) prev ^= bit[i];
    }
    for (int b:bit) cout << b;
    cout << endl;
}
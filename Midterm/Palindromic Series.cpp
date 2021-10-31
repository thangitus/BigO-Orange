#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        string num = to_string(n), s;
        int sum = 0, k = 0;
        for (char c:num)sum += (c - '0');
        while (s.length() < sum) {
            s += num[k % num.length()];
            k++;
        }
        string p = s;
        reverse(p.begin(), p.end());
        if (p == s)cout << "YES\n";
        else cout << "NO\n";
    }
}
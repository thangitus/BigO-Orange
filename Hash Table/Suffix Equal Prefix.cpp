#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        string line;
        cin >> line;
        int result = 0, len = line.length(), left[len + 1], right[len + 1], base = 31, p = 1;
        left[0] = 0, right[len] = 0;
        for (int i = 1; i <= len; i++)
            left[i] = (line[i - 1] - 'a' + 1 + base * left[i - 1]);
        for (int i = len - 1; i >= 0; i--) {
            right[i] = ((line[i] - 'a' + 1) * p + right[i + 1]);
            p = (1LL * p * base);
        }
        for (int i = 1; i < len; i++)
            result += left[i] == right[len - i];
        cout << "Case " << k << ": " << result << endl;
    }
}
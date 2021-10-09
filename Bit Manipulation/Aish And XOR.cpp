#include <bits/stdc++.h>


using namespace std;

int main() {
    int n, q, l, r, num;
    cin >> n;
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int countOne = sum[r] - sum[l - 1];
        int countZero = r - l + 1 - countOne;
        if (countOne % 2) cout << 1;
        else cout << 0;
        cout << " " << countZero << endl;
    }
}
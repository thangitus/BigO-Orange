#include <bits/stdc++.h>

using namespace std;
typedef long long long2;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long2> endWith0(n + 1), endNot0(n + 1);
    endWith0[1] = 0, endNot0[1] = k - 1;
    for (int i = 2; i <= n; i++) {
        endWith0[i] = endNot0[i - 1];
        endNot0[i] = (endNot0[i - 1] + endWith0[i - 1]) * (k - 1);
    }
    cout << endWith0[n] + endNot0[n] << endl;
}
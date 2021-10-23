#include <bits/stdc++.h>


using namespace std;
const int MAX = 50002;
int dp[MAX];

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result = result / i * (i - 1);
        }
    }
    if (n > 1) result = result / n * (n - 1);
    return result;
}

int main() {
    dp[1] = 1;
    for (int i = 2; i < MAX; i++)
        dp[i] = dp[i - 1] + 2 * phi(i);

    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        cout << dp[n] << endl;
    }
}
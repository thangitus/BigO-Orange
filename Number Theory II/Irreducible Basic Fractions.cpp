#include <bits/stdc++.h>


using namespace std;

long long phi(int n) {
    long long result = n;
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
    int n;
    while (true) {
        cin >> n;
        if (!n) break;
        auto result = phi(n);
        cout << result << endl;
    }
}
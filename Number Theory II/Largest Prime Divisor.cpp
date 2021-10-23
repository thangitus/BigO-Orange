#include <bits/stdc++.h>


using namespace std;
typedef long long long2;

long2 primeDivisor(long2 n) {
    if (n < 0) n *= -1;
    long2 result = -1, count = 0;

    for (long2 i = 2; i * i <= n && n != 1; i++) {
        while (n % i == 0) {
            n /= i;
            result = i;
        }
        count += result == i;
    }

    if (n != 1 && result != -1) result = n;
    else if (count == 1) result = -1;
    return result;

}

int main() {
    long2 n;
    while (true) {
        cin >> n;
        if (!n) break;
        auto result = primeDivisor(n);
        cout << result << endl;
    }
}
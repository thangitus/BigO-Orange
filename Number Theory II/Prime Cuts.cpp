#include <bits/stdc++.h>


using namespace std;

vector<int> primes;
const int MAX = 1001;

int main() {
    vector<bool> isPrime(MAX, true);
    for (int i = 2; i < MAX; i++)
        if (isPrime[i]) {
            for (int j = 2 * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    for (int i = 1; i < MAX; i++)
        if (isPrime[i]) primes.push_back(i);

    int n, c;
    while (cin >> n >> c) {
        cout << n << ' ' << c << ": ";
        int num = 0, start;
        while (num < primes.size() && primes[num] <= n)num++;
        if (num & 1) c = c * 2 - 1;
        else c *= 2;
        start = num / 2 - c / 2;
        start = max(start, 0), c = min({c, num, (int) primes.size()});
        for (int i = start; i < start + c; i++)
            cout << primes[i] << " ";
        cout << endl;
    }
}
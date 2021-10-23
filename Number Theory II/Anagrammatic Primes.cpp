#include <bits/stdc++.h>


using namespace std;
const int MAX = 10000000;

int main() {
    vector<int> anagrammaticPrimes;
    vector<bool> isPrime(MAX, true);

    for (int i = 2; i < MAX; i++)
        if (isPrime[i]) {
            for (int j = 2 * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    for (int i = 2; i < MAX; i++) {
        if (!isPrime[i]) continue;
        bool isAnagram = true;
        string num = to_string(i);
        sort(num.begin(), num.end());
        do {
            int n = stoi(num);
            if (!isPrime[n]) isAnagram = false;
        } while (next_permutation(num.begin(), num.end()) && isAnagram);
        if (isAnagram) anagrammaticPrimes.push_back(i);
    }

    while (true) {
        int n, result = 0;
        cin >> n;
        if (!n) break;
        int nextPow = pow(10, to_string(n).length());
        for (int &num:anagrammaticPrimes) {
            if (num >= nextPow)break;
            if (num > n) {
                result = num;
                break;
            }
        }
        cout << result << endl;
    }
}
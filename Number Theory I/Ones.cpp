#include <bits/stdc++.h>


using namespace std;


int main() {
    int n;
    while (cin >> n) {
        int i = 1, num = 1;
        for (;; i++) {
            if (num % n == 0) break;
            num = num * 10 + 1;
            num %= n;
        }
        cout << i << endl;
    }
}

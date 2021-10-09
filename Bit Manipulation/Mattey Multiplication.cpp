#include<bits/stdc++.h>

using namespace std;

/**
 * m = (1<<p0) + (1<<p1) + .. + (1<<pi)
 * n * m = n*((1<<p0) + (1<<p1) + .. + (1<<pi))
 *       = n*((2^p0) + (2^p1) + .. + (2^pi))
 *       = (n*2^p0) + (n*2^p1) + .. + (n*2^pi)
 *       = (n<<p0) + (n<<p1) + . + (n<<pi)
 * */
long long int findP(long long int n) {
    if (n == 0) return 0;
    long long int msb = 0;
    while (n) {
        n >>= 1;
        msb++;
    }
    msb--;
    return msb;

}

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, m, p, count = 0, i = 1;
        cin >> n >> m;
        while (m) {
            if (count++) cout << " " << "+" << " ";
            p = findP(m);
            cout << "(" << n << "<<" << p << ")";
            m -= (i << p);
        }
        cout << endl;
    }
}


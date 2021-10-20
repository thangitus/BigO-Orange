#include <bits/stdc++.h>


using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, b, num, k, result = 0;
        cin >> n >> b;
        while (b--) {
            cin >> k;
            int box = 1;
            while (k--) {
                cin >> num;
                num %= n;
                box *= num;
                box %= n;
            }
            result += box;
            result %= n;
        }
        cout << result << endl;
    }
}

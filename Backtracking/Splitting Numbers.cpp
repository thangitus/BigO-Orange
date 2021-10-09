#include <bits/stdc++.h>


using namespace std;

int main() {
    unsigned int n;
    do {
        cin >> n;
        if (!n) break;
        unsigned int a = 0, b = 0;
        vector<int> bitOne;
        for (int i = 0; i < 32; i++) {
            if (n & 1) bitOne.push_back(i);
            n >>= 1;
        }
        for (int i = 0; i < bitOne.size(); i++) {
            if (!(i & 1))
                a |= (1 << bitOne[i]);
            else b |= (1 << bitOne[i]);
        }

        cout << a << " " << b << endl;
    } while (true);
}
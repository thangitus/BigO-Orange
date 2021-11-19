#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, k, n;
    cin >> t;
    while (t--) {
        cin >> k >> n;
        int prices[n];
        for (int &price: prices)cin >> price;
        vector<int> sell(k + 1, 0), buy(k + 1, INT_MIN);
        for (int price: prices)
            for (int i = 1; i <= k; i++) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        cout << sell[k] << endl;
    }
}
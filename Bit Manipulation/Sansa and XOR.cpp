#include <bits/stdc++.h>


using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, result = 0;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        if (n % 2 == 0) cout << 0 << endl;
        else {
            for (int i = 0; i < n; i++)
                if (!(i & 1))
                    result ^= nums[i];
            cout << result << endl;
        }
    }
}
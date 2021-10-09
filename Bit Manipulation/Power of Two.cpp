#include <bits/stdc++.h>


using namespace std;

int main() {
    long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> nums(n);
        bool check = false;
        for (int i = 0; i < n; i++)cin >> nums[i];
        for (int i = 0; i < 32 && !check; i++) {
            long result = LONG_MAX; //11111111111111111111111111111111
            for (int j = 0; j < n; j++)
                if (nums[j] & (1 << i)) // nums[j] has bit 1 at index i
                    result = result & nums[j];
            if (result > 0 && !(result & (result - 1))) {
                check = true;
            }
        }
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
}

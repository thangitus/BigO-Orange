#include <bits/stdc++.h>

using namespace std;
typedef long long long2;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> nums(n);
        for (int &num:nums) cin >> num;
        long2 result = 0LL;
        for (int i = 0; i < 32; ++i) {
            long2 sol = 0;
            long2 parity[2] = {1LL, 0LL};
            int num = 0;
            for (int j = 0; j < n; ++j) {
                long2 bit_mask = (1LL << i);
                int cur = (bit_mask & nums[j]) > 0 ? 1 : 0;
                num += cur;
                sol += parity[1 - num % 2];
                parity[num % 2]++;
            }
            result += sol * (1LL << i);
        }
        cout << result << endl;
    }
}
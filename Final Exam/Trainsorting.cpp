#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, result = 0;
        cin >> n;
        vector<int> nums(n), inc(n, 1), dec(n, 1);
        for (int &num: nums) cin >> num;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++)
                if (nums[i] > nums[j])
                    dec[i] = max(dec[i], dec[j] + 1);
                else if (nums[j] > nums[i])
                    inc[i] = max(inc[i], inc[j] + 1);
        }
        for (int i = 0; i < n; i++)
            result = max(result, inc[i] + dec[i] - 1);
        cout << result << endl;
    }
}
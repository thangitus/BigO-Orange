#include <bits/stdc++.h>


using namespace std;

int main() {
    int n;
    do {
        cin >> n;
        if (!n) break;
        long long result = 0, buy = 0, sell = 0;
        vector<int> nums(n);
        for (int &num:nums) cin >> num;
        while (buy < n && sell < n) {
            while (buy < n && nums[buy] <= 0) buy++;
            while (sell < n && nums[sell] >= 0) sell++;
            int numBottle = min(nums[buy], abs(nums[sell]));
            result += numBottle * abs(buy - sell);
            nums[buy] -= numBottle;
            nums[sell] += numBottle;
        }
        cout << result << endl;
    } while (true);

}

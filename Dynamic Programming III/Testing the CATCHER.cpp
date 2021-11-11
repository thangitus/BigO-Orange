#include <bits/stdc++.h>

using namespace std;

int main() {
    int num, c = 1;
    do {
        cin >> num;
        if (num == -1) break;
        cout << "Test #" << c++ << ":\n";
        cout << "  maximum possible interceptions: ";
        vector<int> nums;
        do {
            nums.push_back(num);
            cin >> num;
            if (num == -1) break;
        } while (true);
        reverse(nums.begin(), nums.end());
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] >= sub.back())
                sub.push_back(nums[i]);
            else {
                auto index = upper_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                sub[index] = nums[i];
            }

            cout << sub.size() << "\n\n";
    } while (true);
}
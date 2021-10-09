#include <bits/stdc++.h>


using namespace std;

void combination(vector<int> &cur, vector<int> &nums, int left, int k) {
    if (k == 0) {
        for (int &i:cur)
            cout << i << " ";
        cout << endl;
        return;
    }
    for (int i = left; i < nums.size(); i++) {
        cur.push_back(nums[i]);
        combination(cur, nums, i + 1, k - 1);
        cur.pop_back();
    }
}

int main() {
    int k;
    do {
        cin >> k;
        if (k == 0) break;
        vector<int> nums(k);
        for (int i = 0; i < k; i++) cin >> nums[i];
        vector<int> cur;
        combination(cur, nums, 0, 6);
        cout << endl;
    } while (true);
}
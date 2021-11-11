#include <bits/stdc++.h>

using namespace std;
const int MAX = 250 * 250 + 1;

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n, p, q, num, curPos = 1, nums[MAX];
        cin >> n >> p >> q;
        p++, q++;
        unordered_map<int, int> pos;
        for (int i = 1; i <= p; i++) {
            cin >> num;
            pos[num] = i;
        }
        for (int i = 1; i <= q; i++) {
            cin >> num;
            if (pos[num]) nums[curPos++] = pos[num];
        }
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int i = 1; i < curPos - 1; i++)
            if (nums[i] >= sub.back())
                sub.push_back(nums[i]);
            else {
                auto index = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                sub[index] = nums[i];
            }

        cout << "Case " << k << ": " <<sub.size() << endl;
    }
}
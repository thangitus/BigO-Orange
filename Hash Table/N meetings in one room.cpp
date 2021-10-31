#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
    if (a[1] != b[1])
        return a[1] < b[1];
    return a[0] < b[0];
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> activities(n, vector<int>(3));
        vector<vector<int>> result;
        for (auto &activity:activities) cin >> activity[0];
        for (auto &activity:activities) cin >> activity[1];
        for (int i = 1; i <= n; i++) activities[i - 1][2] = i;
        sort(activities.begin(), activities.end(), compare);

        result.push_back(activities[0]);
        for (int i = 1; i < n; i++) {
            if (activities[i][0] > result.back()[1])
                result.push_back(activities[i]);
        }
        for (auto &item:result)
            cout << item[2] << " ";
        cout << endl;
    }
}
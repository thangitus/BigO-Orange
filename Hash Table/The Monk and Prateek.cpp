#include <bits/stdc++.h>

using namespace std;

int r3gz3n(int n) {
    int sum = 0, tmp = n;
    while (tmp) {
        sum += tmp % 10;
        tmp /= 10;
    }
    return sum ^ n;
}

int main() {
    int n, num, value;
    int maxValue, maxCount = 0, actMinValue, collision = 0;
    maxValue = INT_MIN;
    actMinValue = INT_MAX;
    cin >> n;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        cin >> num;
        value = r3gz3n(num);
        maxValue = max(maxValue, value);
        if (count[value]) collision++;
        count[value]++;
    }
    if (collision) {
        for (auto &item : count) {
            if (item.second == maxCount)
                actMinValue = min(item.first, actMinValue);
            else if (item.second > maxCount) {
                actMinValue = item.first;
                maxCount = item.second;
            }
        }
    }

    if (maxCount == 0)cout << maxValue;
    else cout << actMinValue;
    cout << " " << collision << endl;
}
#include <bits/stdc++.h>

using namespace std;
struct People {
    int strength, beauty, index;
};

int lower_bound(vector<People> &arr, vector<int> &sub, int n, People &x) {
    int left = 0, right = n, pos = right;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int index = sub[mid];
        if (arr[index].beauty >= x.beauty) {
            pos = mid;
            right = mid;
        } else left = mid + 1;
    }
    return pos;
}

vector<int> lis(vector<People> &arr) {
    int n = arr.size();
    vector<int> path(n, -1), dp, result;
    dp.push_back(0);
    for (int i = 1; i < n; i++) {
        if (arr[i].beauty <= arr[dp[0]].beauty)
            dp[0] = i;
        else if (arr[i].beauty > arr[dp.back()].beauty) {
            path[i] = dp.back();
            dp.push_back(i);
        } else {
            int pos = lower_bound(arr, dp, dp.size(), arr[i]);
            path[i] = dp[pos - 1];
            dp[pos] = i;
        }
    }
    int i = dp.back();
    while (i >= 0) {
        result.push_back(arr[i].index);
        i = path[i];
    }
    reverse(result.begin(), result.end());
    return result;
}

bool compare(People &a, People &b) {
    if (a.strength != b.strength) return a.strength < b.strength;
    return a.beauty > b.beauty;
}

int main() {
    int n;
    cin >> n;
    vector<People> peoples(n);
    for (int i = 0; i < n; ++i) {
        cin >> peoples[i].strength >> peoples[i].beauty;
        peoples[i].index = i + 1;
    }
    sort(peoples.begin(), peoples.end(), compare);
    auto path = lis(peoples);
    cout << path.size() << endl;
    for (int i:path) cout << i << ' ';
    cout << endl;
}
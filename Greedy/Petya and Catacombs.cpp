#include <bits/stdc++.h>


using namespace std;

int main() {
    int n, num, result = 1;
    unordered_set<int> seen;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (seen.count(num)) result++;
        seen.insert(num);
    }
    cout << result;
}


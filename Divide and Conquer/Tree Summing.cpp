#include <bits/stdc++.h>


using namespace std;

bool dfs(int curSum, bool &isNull) {
    int value;
    char c;
    cin >> c;
    bool result = false, leftNull = false, rightNull = false;
    if (cin >> value) {
        curSum -= value;
        bool left = dfs(curSum, leftNull);
        bool right = dfs(curSum, rightNull);
        result = left || right;
    } else isNull = true;
    if (leftNull && rightNull)
        result = curSum == 0;
    cin.clear();
    cin >> c;
    return result;
}

int main() {
    int sum;
    while (cin >> sum) {
        bool isNull = false;
        bool result = dfs(sum, isNull);
        if (result) cout << "yes\n";
        else cout << "no\n";
    }
}
#include <bits/stdc++.h>

using namespace std;
int expect = 0;
int cnt = 0, total = 0;

void dfs(string &s, int index, int value) {
    if (index == s.length()) {
        if (value == expect) cnt++;
        total++;
        return;
    }
    if (s[index] == '?') {
        dfs(s, index + 1, value + 1);
        dfs(s, index + 1, value - 1);
        return;
    }
    if (s[index] == '+') value++;
    if (s[index] == '-') value--;
    dfs(s, index + 1, value);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (char &ch:s1)
        if (ch == '+') expect++;
        else expect--;
    dfs(s2, 0, 0);
    double result;
    if (total == 0) {
        if (cnt == 0) result = 0;
        else result = 1;
    } else result = double(cnt) / total;
    cout << setprecision(10) << fixed << result;
}
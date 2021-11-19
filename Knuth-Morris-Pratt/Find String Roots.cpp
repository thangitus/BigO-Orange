#include <bits/stdc++.h>

using namespace std;

vector<int> createPrefix(string &s) {
    int len = s.length(), i = 1, j = 0;
    vector<int> prefix(len);
    while (i < len) {
        if (s[i] == s[j]) prefix[i++] = ++j;
        else {
            if (j != 0) j = prefix[j - 1];
            else prefix[i++] = 0;
        }
    }
    return prefix;
}

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "*") break;
        auto prefix = createPrefix(s);
        int len = s.length(), n = len - prefix.back(), result = len / n;
        if (result * n != len) result = 1;
        cout << result << endl;
    }
}

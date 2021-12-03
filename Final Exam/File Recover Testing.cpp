#include <bits/stdc++.h>

using namespace std;

vector<int> createPrefix(string &s) {
    vector<int> prefix(s.length());
    for (int i = 1, j = 0; s[i]; ++i) {
        while (j && s[i] != s[j]) j = prefix[j - 1];
        if (s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return prefix;
}

int main() {
    string s;
    int k;
    while (true) {
        cin >> k;
        if (k == -1) return 0;
        cin >> s;
        int len = s.length(), result = 0;
        auto prefix = createPrefix(s);
        if (k >= len) {
            result = (k - prefix.back()) / (len - prefix.back());
        }
        cout << result << endl;
    }
}
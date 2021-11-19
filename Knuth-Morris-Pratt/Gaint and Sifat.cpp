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

int kmpSearch(string &s, string &t) {
    vector<int> prefix = createPrefix(t);
    int n = s.length(), m = t.length(), i = 0, j = 0, result = 0;
    while (i < n) {
        if (s[i] == t[j]) i++, j++;
        if (j == m) {
            result++;
            j = prefix[j - 1];
        } else if (i < n && s[i] != t[j]) {
            if (j != 0) j = prefix[j - 1];
            else i++;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        string s, p, tmp;
        getline(cin, tmp);
        getline(cin, tmp);
        for (char c: tmp)
            if (isalpha(c)) s += c;
        cin >> p;
        int result = kmpSearch(s, p);
        cout << "Case " << k << ": " << result << endl;
    }
}
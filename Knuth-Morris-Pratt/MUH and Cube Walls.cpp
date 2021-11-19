#include <bits/stdc++.h>

using namespace std;

vector<int> createPrefix(vector<int> &s) {
    int len = s.size();
    vector<int> prefix(len);
    for (int i = 1, j = 0; i < len; ++i) {
        while (j && s[i] != s[j]) j = prefix[j - 1];
        if (s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return prefix;
}

int kmpSearch(vector<int> &s, vector<int> &t) {
    vector<int> prefix = createPrefix(t);
    int n = s.size(), m = t.size(), i = 0, j = 0, result = 0;
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
    int n, w;
    cin >> n >> w;
    vector<int> s(n), t(w);
    for (int &i: s) cin >> i;
    for (int &i: t) cin >> i;
    for (int i = 0; i < n - 1; i++)
        s[i] = s[i + 1] - s[i];
    for (int i = 0; i < w - 1; i++)
        t[i] = t[i + 1] - t[i];
    s.pop_back(), t.pop_back();
    if (t.empty()) cout << s.size() + 1 << endl;
    else cout << kmpSearch(s, t) << endl;
}
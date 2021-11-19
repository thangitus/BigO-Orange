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
    cin >> s;
    auto prefix = createPrefix(s);
    int x = prefix.back();
    unordered_set<int> seen;
    for (int i = 0; i < prefix.size() - 1; i++)
        seen.insert(prefix[i]);
    while (x != 0 && !seen.count(x))
        x = prefix[x - 1];
    if (x) cout << s.substr(0, x) << endl;
    else cout << "Just a legend\n";
}



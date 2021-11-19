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

string kmpSearch(string &s, string &t, int k) {
    vector<int> prefix = createPrefix(t);
    int n = s.length(), m = t.length(), i = 0, j = 0, len = 0, count = 0;
    vector<int> nums;
    while (i < n) {
        if (s[i] == t[j]) i++, j++;
        nums.push_back(j);
        if (j == m) {
            len++;
            j = prefix[j - 1];
        } else if (i < n && s[i] != t[j]) {
            if (j != 0) j = prefix[j - 1];
            else i++;
        }
    }
    sort(nums.begin(), nums.end(), greater<>());
    for (int num: nums) {
        if (num) count++;
        if (count >= k) {
            len = num;
            break;
        }
    }
    if (len == 0) return "IMPOSSIBLE";
    return t.substr(0, len);
}

int main() {
    int k;
    string s, t;
    getline(cin, s);
    getline(cin, t);
    cin >> k;
    cout << kmpSearch(s, t, k) << endl;
}
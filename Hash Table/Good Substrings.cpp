#include <bits/stdc++.h>

using namespace std;
typedef long long long2;

int main() {
    string s;
    int k, countBad = 0, left = 1;
    vector<bool> isBad(26);
    unordered_set<long2> set;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        char c;
        cin >> c;
        isBad[i] = c == '0';
    }
    cin >> k;

    int len = s.length(), base = 31;
    long2 hash[len + 1], pow[len + 1];
    hash[0] = 0, pow[0] = 1;
    for (int i = 1; i <= len; i++)
        pow[i] = pow[i - 1] * base;
    for (int i = 1; i <= len; i++)
        hash[i] = (s[i - 1] - 'a' + 1 + base * hash[i - 1]);

    for (int i = 1; i <= len; i++) {
        countBad += isBad[s[i - 1] - 'a'];
        while (left <= i && countBad > k) {
            countBad -= isBad[s[left - 1] - 'a'];
            left++;
        }
        int j = left;
        while (j <= i) {
            set.insert((hash[i] - hash[j - 1] * pow[i - j + 1]));
            j++;
        }
    }
    cout << set.size() << endl;
}
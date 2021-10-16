#include <bits/stdc++.h>


using namespace std;

int main() {
    string s;
    long long sum = 0, result = 0, n;
    cin >> n >> s;
    for (char &c:s) sum += c - '0';
    sort(s.begin(), s.end(), greater<>());
    for (auto i = s.length() - 1; i >= 0 && sum < n; i--) {
        if (s[i] == '9') continue;
        sum += 9 - (s[i] - '0');
        result++;
    }
    cout << result << endl;
}
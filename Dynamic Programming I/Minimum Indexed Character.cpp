#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, p;
        cin >> s >> p;
        vector<int> pos(128, -1);
        for (int i = s.length() - 1; i >= 0; i--)
            pos[s[i]] = i;
        int minIndex = INT_MAX;
        char result;
        for (char c:p) {
            if (pos[c] != -1 && pos[c] < minIndex) {
                minIndex = pos[c];
                result = c;
            }
        }
        if (minIndex != INT_MAX)
            cout << result << endl;
        else cout << "No character present\n";
    }
}
#include<bits/stdc++.h>


using namespace std;

int countBitOne(int num) {
    int count = 0;
    while (num) {
        if (num & 1) count++;
        num >>= 1;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int max_value = 1 << k;
        int result = n;
        for (int i = 1; i < max_value; i++) {
            bool satisfied_choice = true;
            for (int v = 0; v < n; v++) {
                bool flag = false;
                for (int u = 0; u < k; u++) {
                    if (arr[v][u] == '1' && (i & (1 << u))) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    satisfied_choice = false;
                    break;
                }
            }
            if (satisfied_choice) result = min(result, countBitOne(i));
        }
        cout << result << endl;
    }
    return 0;
}
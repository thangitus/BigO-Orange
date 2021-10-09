#include <bits/stdc++.h>


using namespace std;
int t, n, h;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> h;
        vector<int> arr(n);
        for (int i = n - h; i < n; i++) arr[i] = 1;
        do {
            for (int i = 0; i < n; i++) cout << arr[i];
            cout << endl;
        } while (next_permutation(arr.begin(), arr.end()));
        cout << endl;
    }
    return 0;
}
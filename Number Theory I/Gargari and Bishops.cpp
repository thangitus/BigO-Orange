#include <bits/stdc++.h>

typedef long long long2;
using namespace std;

int main() {
    int n;
    long2 result[2][3]{0};
    cin >> n;
    vector<vector<int>> coin(n, vector<int>(n));

    //left: start from left -> right. right: start from right -> left
    vector<long2> left(n * 2), right(n * 2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> coin[i][j];
            right[i + j] += coin[i][j];
            left[n + i - j] += coin[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            long2 value = right[i + j] + left[n + i - j] - coin[i][j];
            int id = (i + j) & 1;
            if (value >= result[id][0]) {
                result[id][0] = value;
                result[id][1] = i + 1;
                result[id][2] = j + 1;
            }
        }
    cout << result[0][0] + result[1][0] << endl;
    cout << result[0][1] << " " << result[0][2] << " " << result[1][1] << " " << result[1][2] << endl;
}

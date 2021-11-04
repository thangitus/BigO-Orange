#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> row(m, 1), col(n, 1);
    vector<vector<int>> matrix(m, vector<int>(n)), result = matrix;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            row[i] &= matrix[i][j];
            col[j] &= matrix[i][j];
        }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) {
                if (row[i] && col[j])
                    result[i][j] = 1;
                else if (!row[i] && !col[j]) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;
int board[8][8];
vector<int> row;
int result;

bool isValid(int r, int c) {
    for (int i = 0; i < c; i++) {
        if (row[i] == r || (abs(row[i] - r) == abs(i - c))) {
            return false;
        }
    }
    return true;
}

void backtracking(int c, int sum) {
    if (c == 8) {
        result = max(result, sum);
        return;
    }
    for (int r = 0; r < 8; r++) {
        if (isValid(r, c)) {
            row[c] = r;
            backtracking(c + 1, sum + board[r][c]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        result = 0;
        row = vector<int>(8);
        for (auto &r:board)
            for (int &i:r) cin >> i;
        backtracking(0, 0);
        cout << setw(5) << result << endl;
    }
}
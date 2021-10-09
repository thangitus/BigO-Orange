#include <bits/stdc++.h>

using namespace std;
int n = 4;

int dx[]{-1, -1, -1, 0, 0, 1, 1, 1};
int dy[]{-1, 0, 1, -1, 1, -1, 0, 1};

unordered_set<char> vowels{'A', 'E', 'I', 'O', 'U', 'Y'};

void
backtracking(string &cur, char board[][4], int x, int y, int countVowel, unordered_set<string> &result) {
    if (cur.length() == 4) {
        if (countVowel == 2)
            result.insert(cur);
        return;
    }
    if (countVowel > 2) return;
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX < 0 || newX >= 4 || newY < 0 || newY >= 4) continue;
        char c = board[newX][newY];
        if (board[newX][newY] != '#') {
            cur.push_back(c);
            board[newX][newY] = '#';
            if (vowels.count(c))
                backtracking(cur, board, newX, newY, countVowel + 1, result);
            else backtracking(cur, board, newX, newY, countVowel, result);
            cur.pop_back();
            board[newX][newY] = c;
        }
    }
}

int main() {
    string line;
    char board1[4][4], board2[4][4];
    char c;
    do {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 8; j++) {
                cin >> c;
                if (c == '#')return 0;
                if (j < 4) board1[i][j] = c;
                else board2[i][j - 4] = c;
            }
        unordered_set<string> result1, result2;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                string tmp1, tmp2;
                backtracking(tmp1, board1, i, j, 0, result1);
                backtracking(tmp2, board2, i, j, 0, result2);
            }
        set<string> result;
        for (auto &s:result1)
            if (result2.count(s)) result.insert(s);
        if (result.empty())
            cout << "There are no common words for this pair of boggle boards.\n";
        else for (auto &s:result) cout << s << endl;
        cout << endl;
        getline(cin, line);
    } while (true);
}
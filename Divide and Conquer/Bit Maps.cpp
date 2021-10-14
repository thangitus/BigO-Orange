#include <bits/stdc++.h>


using namespace std;

void BtoD(vector<vector<char>> &graph, int rowStart, int rowEnd, int colStart, int colEnd, int &countChar) {
    if (rowStart == rowEnd || colStart == colEnd) return;
    int countZero = 0;
    for (int i = rowStart; i < rowEnd; i++)
        for (int j = colStart; j < colEnd; j++)
            countZero += graph[i][j] == '0';
    if (countChar > 0 && countChar % 50 == 0) cout << endl;
    countChar++;
    if (countZero == (rowEnd - rowStart) * (colEnd - colStart))
        cout << '0';
    else if (countZero == 0) cout << '1';
    else {
        cout << 'D';
        int rowMid = (rowStart + rowEnd + 1) / 2;
        int colMid = (colStart + colEnd + 1) / 2;
        BtoD(graph, rowStart, rowMid, colStart, colMid, countChar);
        BtoD(graph, rowStart, rowMid, colMid, colEnd, countChar);
        BtoD(graph, rowMid, rowEnd, colStart, colMid, countChar);
        BtoD(graph, rowMid, rowEnd, colMid, colEnd, countChar);
    }
}

void DtoB(vector<vector<char>> &result, int rowStart, int rowEnd, int colStart, int colEnd) {
    if (rowStart == rowEnd || colStart == colEnd) return;
    char ch;
    cin >> ch;
    if (ch == '0' || ch == '1') {
        for (int i = rowStart; i < rowEnd; i++)
            for (int j = colStart; j < colEnd; j++)
                result[i][j] = ch;
        return;
    } else {
        int rowMid = (rowStart + rowEnd + 1) / 2;
        int colMid = (colStart + colEnd + 1) / 2;
        DtoB(result, rowStart, rowMid, colStart, colMid);
        DtoB(result, rowStart, rowMid, colMid, colEnd);
        DtoB(result, rowMid, rowEnd, colStart, colMid);
        DtoB(result, rowMid, rowEnd, colMid, colEnd);
    }
}

int main() {
    char type;
    int n, m;
    do {
        cin >> type;
        if (type == '#') break;
        cin >> n >> m;
        vector<vector<char>> graph(n, vector<char>(m));
        cout << (type == 'B' ? "D" : "B");
        cout << right << setw(4) << n;
        cout << right << setw(4) << m << endl;

        if (type == 'B') {
            for (auto &row:graph)
                for (char &ch:row) cin >> ch;
            int countChar = 0;
            BtoD(graph, 0, n, 0, m, countChar);
        } else {
            DtoB(graph, 0, n, 0, m);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    int index = i * m + j;
                    if (index > 0 && index % 50 == 0) cout << endl;
                    cout << graph[i][j];
                }
        }
        cout << endl;
    } while (true);
}
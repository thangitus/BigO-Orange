#include <bits/stdc++.h>


using namespace std;
typedef long long long2;
int t, n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
unordered_set<long2> seen;

void backtracking(vector<vector<char>> &graph, int x, int y, int count, long2 mask) {
    graph[x][y] = '.';
    int index = x * n + y;
    mask |= (1LL << index);
    if (count == 8)
        seen.insert(mask);
    else {
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
            if (graph[newX][newY] == 'X')
                backtracking(graph, newX, newY, count + 1, mask);
        }
    }
    graph[x][y] = 'X';
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<char>> graph(n, vector<char>(n));
        seen.clear();
        for (int i = 0; i < n; i++)
            for (char &c:graph[i]) cin >> c;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 'X')
                    backtracking(graph, i, j, 1, 0LL);
            }
        cout << seen.size() << endl;
    }
}
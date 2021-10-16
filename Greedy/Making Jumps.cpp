#include <bits/stdc++.h>


using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int n, a, b, t = 1, visitedNode, totalNode;

void dfs(vector<vector<int>> &graph, int x, int y, int countNode) {
    graph[x][y] = 0;
    bool noRoute = true;
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX < 0 || newX >= n || newY < 0 || newY >= 10) continue;
        if (graph[newX][newY]) {
            noRoute = false;
            dfs(graph, newX, newY, countNode + 1);
        }
    }
    if (noRoute) visitedNode = max(visitedNode, countNode);
    graph[x][y] = 1;
}

int main() {
    do {
        cin >> n;
        if (!n) break;
        visitedNode = totalNode = 0;
        vector<vector<int>> graph(n, vector<int>(10));
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            for (int j = a; j < a + b; j++) {
                graph[i][j] = 1;
                totalNode++;
            }
        }
        int y = 0, result;
        for (int j = 0; j < 10; j++)
            if (graph[0][j]) {
                y = j;
                break;
            }
        dfs(graph, 0, y, 1);
        result = totalNode - visitedNode;
        cout << "Case " << t++ << ", " << result << " square";
        if (result != 1) cout << 's';
        cout << " can not be reached.\n";
    } while (true);
}


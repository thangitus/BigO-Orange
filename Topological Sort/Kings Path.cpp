#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};

int main() {
    map<pair<int, int>, bool> visited, path;
    map<pair<int, int>, int> dist;
    pair<int, int> start, end;
    queue<pair<int, int>> queue;
    int n, r, a, b;
    cin >> start.first >> start.second >> end.first >> end.second;
    cin >> n;
    while (n--) {
        cin >> r >> a >> b;
        for (int i = min(a, b); i <= max(a, b); i++)
            path[{r, i}] = true;
    }
    queue.push(start);
    while (!queue.empty()) {
        auto &top = queue.front();
        queue.pop();
        for (int i = 0; i < 8; i++) {
            int x = top.first + dx[i];
            int y = top.second + dy[i];
            if (path[{x, y}] && !visited[{x, y}]) {
                dist[{x, y}] = dist[{top.first, top.second}] + 1;
                queue.push({x, y});
            }
            visited[{x, y}] = true;
        }
    }
    if (visited[end])
        cout << dist[end];
    else cout << -1;
    return 0;
}
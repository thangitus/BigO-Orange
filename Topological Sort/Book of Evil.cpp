#include <bits/stdc++.h>


using namespace std;
const int MAX = 1e5 + 5;
vector<vector<int>> graph(MAX);


void dfs(int parent, int u, int deep, vector<int> &dist) {
    dist[u] = deep;
    for (int &v:graph[u])
        if (v != parent)
            dfs(u, v, deep + 1, dist);
}

int main() {
    int n, m, d, u, v, a = 0, b = 0, result = 0;
    cin >> n >> m >> d;
    vector<int> d1(n + 1), d2(n + 1), p(m + 1);
    for (int i = 0; i < m; i++) cin >> p[i];
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, 1, 0, d1);
    for (int &i:p) if (d1[i] > d1[a]) a = i;

    dfs(0, a, 0, d1);
    for (int &i:p) if (d1[i] > d1[b]) b = i;

    dfs(0, b, 0, d2);
    for (int i = 1; i <= n; i++)
        if (d1[i] <= d && d2[i] <= d) result++;
    cout << result;
    return 0;
}
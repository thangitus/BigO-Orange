#include <bits/stdc++.h>

using namespace std;
vector<int> startTime;
vector<int> finishTime;

void dfs(vector<vector<int>> &graph, int &t, int v) {
    startTime[v] = ++t;
    for (int u : graph[v]) {
        if (!startTime[u])
            dfs(graph, t, u);
    }
    finishTime[v] = ++t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, s, a, b;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int t = 0;
    startTime.resize(n), finishTime.resize(n);
    dfs(graph, t, 0);
    cin >> q;
    while (q--) {
        cin >> s >> a >> b;
        a--, b--;
        if (s == 1) swap(a, b);
        if (startTime[a] <= startTime[b] && finishTime[a] >= finishTime[b])
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
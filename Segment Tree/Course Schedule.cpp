#include <bits/stdc++.h>


using namespace std;

bool topologicalSort(vector<vector<int>> &graph) {
    int n = graph.size(), count = 0;
    vector<int> degree(n);
    queue<int> queue;
    for (int i = 0; i < n; i++)
        for (int &v: graph[i]) degree[v]++;
    for (int i = 0; i < n; i++)
        if (!degree[i]) queue.push(i);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        count++;
        for (int &v: graph[u])
            if (--degree[v] == 0) queue.push(v);
    }
    return count == n;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    while (m--) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    if (topologicalSort(graph)) cout << "yes\n";
    else cout << "no\n";
}
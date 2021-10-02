#include <bits/stdc++.h>


using namespace std;

bool topologicalSort(vector<vector<int>> &graph, vector<int> &result) {
    int n = graph.size();
    vector<int> degree(n);
    priority_queue<int, vector<int>, greater<>> queue;
    for (int i = 0; i < n; i++) {
        for (int &v:graph[i])
            degree[v]++;
    }
    for (int i = 0; i < n; i++)
        if (!degree[i]) queue.push(i);
    while (!queue.empty()) {
        int u = queue.top();
        queue.pop();
        result.push_back(u + 1);
        for (int &v:graph[u])
            if (--degree[v] == 0)
                queue.push(v);

    }
    return result.size() == n;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
    }
    for (auto &edges:graph)
        sort(edges.begin(), edges.end());
    vector<int> result;
    if (topologicalSort(graph, result)) {
        for (int &i:result)
            cout << i << " ";
    } else cout << "Sandro fails.";
    return 0;
}
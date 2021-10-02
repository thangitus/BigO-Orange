#include <bits/stdc++.h>


using namespace std;

struct CustomCompare {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

bool topologicalSort(vector<vector<int>> &graph, vector<pair<int, int>> &result) {
    int n = graph.size();
    vector<int> degree(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> queue;
    for (int i = 0; i < n; i++) {
        for (int &v:graph[i])
            degree[v]++;
    }
    for (int i = 0; i < n; i++)
        if (!degree[i]) queue.push({1, i});

    while (!queue.empty()) {
        for (int i = queue.size(); i > 0; i--) {
            int level = queue.top().first;
            int u = queue.top().second;
            queue.pop();
            result.emplace_back(level, u);
            for (int &v:graph[u])
                if (--degree[v] == 0)
                    queue.push({level + 1, v});
        }
    }
    return result.size() == n;
}

int main() {
    int t, n, m, u, v;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> m;
        vector<vector<int>> graph(n);
        vector<pair<int, int>> result;
        while (m--) {
            cin >> u >> v;
            graph[v].push_back(u);
        }
        topologicalSort(graph, result);
        cout << "Scenario #" << i << ":\n";
        for (auto &p:result)
            cout << p.first << " " << p.second << endl;

    }
    return 0;
}
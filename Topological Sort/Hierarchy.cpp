#include <bits/stdc++.h>


using namespace std;

void topologicalSort(vector<vector<int>> &graph, vector<int> &result) {
    int n = graph.size(), prev = -1;
    vector<int> degree(n);
    priority_queue<int> queue;
    for (int i = 0; i < n; i++) {
        for (int &v:graph[i])
            degree[v]++;
    }
    for (int i = 0; i < n; i++)
        if (!degree[i]) queue.push(i);
    while (!queue.empty()) {
        int u = queue.top();
        queue.pop();
        result[u] = prev;
        prev = u;
        for (int &v:graph[u])
            if (--degree[v] == 0)
                queue.push(v);

    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n);
    for (int i = 0; i < k; i++) {
        int v, a;
        cin >> a;
        while (a--) {
            cin >> v;
            graph[i].push_back(v - 1);
        }
    }
    vector<int> result(n);
    topologicalSort(graph, result);
    for (int &i:result)
        cout << i + 1 << endl;
    return 0;
}
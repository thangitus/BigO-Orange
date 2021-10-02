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
        result.push_back(u);
        for (int &v:graph[u])
            if (--degree[v] == 0)
                queue.push(v);

    }
    return result.size() == n;
}

int main() {
    int n, m, t = 1;
    while (cin >> n) {
        vector<vector<int>> graph(n);
        vector<string> beverages(n);
        unordered_map<string, int> map;
        vector<int> result;
        string b, b1, b2;
        for (int i = 0; i < n; i++) {
            cin >> beverages[i];
            map[beverages[i]] = i;
        }
        cin >> m;
        while (m--) {
            cin >> b1 >> b2;
            graph[map[b1]].push_back(map[b2]);
        }
        for (auto &edges:graph)
            sort(edges.begin(), edges.end());
        topologicalSort(graph, result);
        cout << "Case #" << t << ": Dilbert should drink beverages in this order:";
        for (int &i:result)
            cout << " " << beverages[i];
        cout << ".\n";
        t++;
        getline(cin, b1); //empty line
    }

    return 0;
}
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
    int n;
    vector<vector<int>> graph(26);
    vector<int> result;
    cin >> n;
    vector<string> name(n);
    for (int i = 0; i < n; i++) cin >> name[i];
    for (int i = 1; i < n; i++) {
        string prev = name[i - 1], cur = name[i];
        int j = 0;
        for (; j < min(prev.length(), cur.length()); j++)
            if (prev[j] != cur[j]) {
                graph[prev[j] - 'a'].push_back(cur[j] - 'a');
                break;
            }
        if (prev.length() > cur.length() && j == cur.length()) {
            cout << "Impossible";
            return 0;
        }
    }
    if (topologicalSort(graph, result))
        for (int &i:result) cout << char(i + 'a');
    else cout << "Impossible";
    return 0;
}
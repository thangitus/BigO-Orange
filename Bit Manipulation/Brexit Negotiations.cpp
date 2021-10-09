#include <bits/stdc++.h>


using namespace std;
vector<int> times;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &result) {
    visited[u] = true;
    for (int &v:graph[u])
        if (!visited[v]) dfs(v, graph, visited, result);
    result.push_back(u);
}

void topologicalSort(vector<vector<int>> &graph, vector<int> &result, vector<int> &order) {
    vector<bool> visited(graph.size());
    for (int &i:order)
        if (!visited[i])
            dfs(i, graph, visited, result);
}

bool compare(int &a, int &b) {
    return times[a] > times[b];
}

int main() {
    int n, d, b;
    cin >> n;
    times.resize(n);
    vector<vector<int>> graph(n);
    vector<int> result, order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i;
        cin >> times[i];
        cin >> d;
        while (d--) {
            cin >> b;
            graph[i].push_back(b - 1);
        }
    }
    sort(order.begin(), order.end(), compare);
    topologicalSort(graph, result, order);
    int ans = 0;
    for (int i = 0; i < result.size(); i++)
        ans = max(ans, times[result[i]] + i);
    cout << ans << endl;
    return 0;
}
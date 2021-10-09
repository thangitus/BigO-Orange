#include <bits/stdc++.h>


using namespace std;
bool isCycle = false;

void dfs(int u, vector<vector<int>> &graph, vector<int> &visited, vector<int> &result) {
    if (visited[u] == 0) {
        visited[u] = 1;
        for (int &v:graph[u])
            dfs(v, graph, visited, result);
        visited[u] = 2;
        result.push_back(u);
    } else if (visited[u] == 1) isCycle = true;
}

void topologicalSort(vector<vector<int>> &graph, vector<int> &result, vector<int> &mainCourse) {
    vector<int> visited(graph.size());
    for (int &i:mainCourse)
        if (!visited[i]) {
            dfs(i, graph, visited, result);
        }
}

int main() {
    int n, k, t, v, course;
    cin >> n >> k;
    vector<vector<int>> graph(n);
    vector<int> mainCourse(k), result;
    for (int i = 0; i < k; i++) {
        cin >> course;
        mainCourse[i] = course - 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        while (t--) {
            cin >> v;
            graph[i].push_back(v - 1);
        }
    }
    topologicalSort(graph, result, mainCourse);
    if (isCycle) cout << -1;
    else {
        cout << result.size() << endl;
        for (int &i:result) cout << i + 1 << " ";
    }
    return 0;
}
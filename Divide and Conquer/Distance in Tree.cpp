#include <bits/stdc++.h>


using namespace std;

int n, k, res = 0;

vector<int> cal_nodes(vector<vector<int>> &graph, int u, int parent) {
    vector<int> count(k + 1);
    count[0] = 1;
    for (int &v : graph[u]) {
        if (v != parent) {
            vector<int> count_v = cal_nodes(graph, v, u);
            for (int i = 0; i < k; ++i)
                res += count[i] * count_v[k - 1 - i];

            for (int i = 1; i <= k; ++i)
                count[i] += count_v[i - 1];
        }
    }
    return count;
}

int main() {
    cin >> n >> k;
    int u, v;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cal_nodes(graph, 0, -1);
    cout << res << endl;
}
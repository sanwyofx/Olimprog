#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    k--;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d(n, -1);
    queue<int> q;

    q.push(k);
    d[k] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << d[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Colorea con BFS desde src: color[src] = 0 y cada vecino recibe el color opuesto.
// Devuelve false si dos vertices adyacentes quedan con el mismo color.
bool Colorear(int src, vector<int>& color, vector<vector<int>>& adj) {
    queue<int> Q;
    color[src] = 0;
    Q.push(src);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                Q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);       // -1 = sin color
    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;   // el grafo puede tener varias componentes
        if (!Colorear(i, color, adj)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "SI\n";
    return 0;
}

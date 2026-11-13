/*
 * DFS3 - ENCONTRAR UN CAMINO ENTRE a Y b (y saber si son alcanzables)
 * USO: "existe camino de a a b? imprimelo". En un arbol el camino es unico.
 *      (Si piden el camino con MENOS aristas usar BFS, ver S14/ALG9.)
 * INPUT : n m a b, luego m lineas "u v" (no dirigido).
 * OUTPUT: -1 si no hay camino; si hay: cantidad de nodos y el camino a ... b.
 * CLAVE : par[v] = desde quien llegue a v; se reconstruye yendo de b hacia a.
 * COMPLEJIDAD: O(n+m)
 */
#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> par(n + 1, 0);
    vector<char> vis(n + 1, 0);
    vector<int> st = {a};
    vis[a] = 1;
    while (!st.empty()) {
        int u = st.back(); st.pop_back();
        for (int v : G[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                par[v] = u;
                st.push_back(v);
            }
        }
    }
    if (!vis[b]) { cout << -1 << '\n'; return 0; }
    vector<int> path;
    for (int x = b; x != a; x = par[x]) path.push_back(x);
    path.push_back(a);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (int x : path) cout << x << ' ';
    cout << '\n';
    return 0;
}

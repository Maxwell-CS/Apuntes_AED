/*
 * DFS9 - LCA (ancestro comun mas bajo) con BINARY LIFTING
 * USO: en un arbol, el ancestro comun mas cercano de a y b; distancia entre
 *      dos nodos = dep[a] + dep[b] - 2*dep[lca]; el k-esimo ancestro.
 * INPUT : n, luego n-1 lineas "u v" (arbol, raiz = 1), luego q,
 *         luego q lineas "a b".
 * OUTPUT: por consulta: lca(a,b) y distancia (en aristas) entre a y b.
 * up[j][v] = ancestro 2^j de v (la raiz se apunta a si misma).
 * COMPLEJIDAD: O((n+q) log n)
 */
#include<bits/stdc++.h>
using namespace std;
const int LOG = 18;                    // 2^18 > 2e5
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<array<int, LOG>> up(n + 1);
    vector<int> dep(n + 1, 0), st = {1};
    vector<char> vis(n + 1, 0);
    vis[1] = 1;
    up[1][0] = 1;
    while (!st.empty()) {              // DFS iterativo: padre y profundidad
        int u = st.back(); st.pop_back();
        for (int v : G[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                up[v][0] = u;
                dep[v] = dep[u] + 1;
                st.push_back(v);
            }
        }
    }
    for (int j = 1; j < LOG; ++j)
        for (int v = 1; v <= n; ++v)
            up[v][j] = up[up[v][j - 1]][j - 1];
    auto lca = [&](int a, int b) {
        if (dep[a] < dep[b]) swap(a, b);
        int diff = dep[a] - dep[b];
        for (int j = 0; j < LOG; ++j)
            if (diff >> j & 1) a = up[a][j];
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; --j)
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        return up[a][0];
    };
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        cout << l << ' ' << dep[a] + dep[b] - 2 * dep[l] << '\n';
    }
    return 0;
}

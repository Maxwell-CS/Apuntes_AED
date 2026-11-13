/*
 * DFS1 - COMPONENTES CONEXAS (DFS recursivo, la plantilla base)
 * USO: contar cuantos "grupos" hay, saber si dos nodos estan conectados,
 *      tamano de cada componente.
 * INPUT : n m, luego m lineas "u v" (no dirigido).
 * OUTPUT: cantidad de componentes, luego comp[i] (id de componente) de cada nodo,
 *         luego el tamano de cada componente.
 * COMPLEJIDAD: O(n+m)
 * OJO: recursion profunda (n ~ 2e5 en cadena) puede dar stack overflow en
 *      algunos jueces -> ver DFS2 (iterativo).
 */
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<int> comp;
int csize;
void dfs(int u, int c) {
    comp[u] = c;
    ++csize;
    for (int v : G[u])
        if (!comp[v]) dfs(v, c);
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    G.assign(n + 1, {});
    comp.assign(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int c = 0;
    vector<int> sizes;
    for (int i = 1; i <= n; ++i) {
        if (comp[i]) continue;
        csize = 0;
        dfs(i, ++c);
        sizes.push_back(csize);
    }
    cout << c << '\n';
    for (int i = 1; i <= n; ++i) cout << comp[i] << ' ';
    cout << '\n';
    for (int s : sizes) cout << s << ' ';
    cout << '\n';
    return 0;
}

/*
 * DFS7 - COMPONENTES FUERTEMENTE CONEXAS (SCC) con TARJAN
 * USO: en un grafo DIRIGIDO, grupos de nodos donde todos se alcanzan entre si.
 *      Condensar el grafo en un DAG, "se puede ir de a a b y volver?".
 * INPUT : n m, luego m lineas "u v" (arista dirigida u -> v).
 * OUTPUT: cantidad de SCC y comp[i] (id de SCC) de cada nodo.
 * NOTA  : Tarjan numera las SCC en orden topologico INVERSO
 *         (comp 0 es una SCC "sumidero": no sale arista hacia otra SCC).
 * COMPLEJIDAD: O(n+m)   (recursivo)
 */
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<int> tin, low, comp, st;
vector<char> onst;
int T = 0, nc = 0;
void dfs(int u) {
    tin[u] = low[u] = ++T;
    st.push_back(u);
    onst[u] = 1;
    for (int v : G[u]) {
        if (!tin[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (onst[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (low[u] == tin[u]) {          // u es raiz de una SCC
        while (true) {
            int x = st.back(); st.pop_back();
            onst[x] = 0;
            comp[x] = nc;
            if (x == u) break;
        }
        ++nc;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    G.assign(n + 1, {});
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    comp.assign(n + 1, -1);
    onst.assign(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
        if (!tin[i]) dfs(i);
    cout << nc << '\n';
    for (int i = 1; i <= n; ++i) cout << comp[i] << ' ';
    cout << '\n';
    return 0;
}

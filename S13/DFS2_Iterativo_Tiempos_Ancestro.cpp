/*
 * DFS2 - DFS ITERATIVO en un ARBOL: tin/tout, profundidad, padre, subarbol
 * USO: (sin riesgo de stack overflow) "es a ancestro/superior de b?",
 *      tamano de subarbol, profundidad, padre. Plantilla para arboles.
 * INPUT : n, luego n-1 lineas "u v" (arbol, raiz = 1),
 *         luego q, luego q lineas "a b".
 * OUTPUT: por cada consulta "SI" si a es ancestro de b (o a==b), sino "NO".
 *         (sz[], dep[], par[] quedan calculados para usar lo que haga falta)
 * REGLA: a es ancestro de b  <=>  tin[a] <= tin[b] && tout[b] <= tout[a]
 * COMPLEJIDAD: O(n + q)
 * Para un grafo general (no arbol): mismo esqueleto con un for sobre todos los
 * nodos no visitados.
 */
#include<bits/stdc++.h>
using namespace std;
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
    vector<int> tin(n + 1, 0), tout(n + 1, 0), par(n + 1, 0), dep(n + 1, 0), sz(n + 1, 1);
    vector<int> it(n + 1, 0), st;
    int T = 0;
    st.push_back(1);
    tin[1] = ++T;
    while (!st.empty()) {
        int u = st.back();
        if (it[u] < (int)G[u].size()) {
            int v = G[u][it[u]++];
            if (v == par[u]) continue;
            par[v] = u;
            dep[v] = dep[u] + 1;
            tin[v] = ++T;
            st.push_back(v);
        } else {
            tout[u] = ++T;
            if (par[u]) sz[par[u]] += sz[u];
            st.pop_back();
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (tin[a] <= tin[b] && tout[b] <= tout[a] ? "SI" : "NO") << '\n';
    }
    return 0;
}

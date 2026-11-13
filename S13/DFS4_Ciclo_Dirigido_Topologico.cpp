/*
 * DFS4 - CICLO EN GRAFO DIRIGIDO + ORDEN TOPOLOGICO (DFS iterativo con colores)
 * USO: "hay dependencias circulares?", ordenar tareas con prerequisitos.
 * INPUT : n m, luego m lineas "u v" (arista dirigida u -> v).
 * OUTPUT: "CICLO" si hay ciclo; si no, un orden topologico (u antes que v
 *         para toda arista u -> v).
 * COLORES: 0 = no visitado, 1 = en la pila actual, 2 = terminado.
 *          Si desde u veo un v con color 1 -> hay ciclo.
 * El orden topologico = orden de salida (postorden) INVERTIDO.
 * (Para imprimir el ciclo concreto ver E_Cycle_Detection.cpp)
 * COMPLEJIDAD: O(n+m)
 */
#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    vector<int> color(n + 1, 0), it(n + 1, 0), order, st;
    bool cyc = false;
    for (int s = 1; s <= n && !cyc; ++s) {
        if (color[s]) continue;
        st.push_back(s);
        color[s] = 1;
        while (!st.empty() && !cyc) {
            int u = st.back();
            if (it[u] < (int)G[u].size()) {
                int v = G[u][it[u]++];
                if (color[v] == 0) {
                    color[v] = 1;
                    st.push_back(v);
                } else if (color[v] == 1) {
                    cyc = true;
                }
            } else {
                color[u] = 2;
                order.push_back(u);
                st.pop_back();
            }
        }
    }
    if (cyc) { cout << "CICLO\n"; return 0; }
    reverse(order.begin(), order.end());
    for (int x : order) cout << x << ' ';
    cout << '\n';
    return 0;
}

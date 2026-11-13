/*
 * DFS5 - GRAFO BIPARTITO (2-coloreo)
 * USO: dividir nodos en 2 grupos sin aristas dentro de un mismo grupo
 *      (equipos rivales, "no pueden estar juntos"). Equivale a: no hay ciclo impar.
 * INPUT : n m, luego m lineas "u v" (no dirigido).
 * OUTPUT: "IMPOSIBLE" si no es bipartito; si lo es, el grupo (1 o 2) de cada nodo.
 * CLAVE : col[v] = 1 - col[u]; si un vecino ya tiene mi mismo color -> imposible.
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
        G[v].push_back(u);
    }
    vector<int> col(n + 1, -1);
    for (int s = 1; s <= n; ++s) {
        if (col[s] != -1) continue;
        col[s] = 0;
        vector<int> st = {s};
        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            for (int v : G[u]) {
                if (col[v] == -1) {
                    col[v] = 1 - col[u];
                    st.push_back(v);
                } else if (col[v] == col[u]) {
                    cout << "IMPOSIBLE\n";
                    return 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << col[i] + 1 << ' ';
    cout << '\n';
    return 0;
}

/*
 * DFS8 - DIAMETRO DE UN ARBOL (2 recorridos)
 * USO: distancia maxima entre dos nodos de un arbol; nodo mas lejano de otro.
 * IDEA: 1) desde cualquier nodo (1) buscar el mas lejano A.
 *       2) desde A buscar el mas lejano B. dist(A,B) es el diametro.
 * INPUT : n, luego n-1 lineas "u v" (arbol, sin pesos).
 * OUTPUT: diametro (en aristas) y los extremos A B.
 * (Con pesos: guardar pares {v,w} y sumar w en vez de +1, usar long long.)
 * COMPLEJIDAD: O(n)
 */
#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> G;
pair<int, int> farthest(int s) {      // {nodo mas lejano, distancia}
    vector<int> d(n + 1, -1), st = {s};
    d[s] = 0;
    pair<int, int> best = {s, 0};
    while (!st.empty()) {
        int u = st.back(); st.pop_back();
        if (d[u] > best.second) best = {u, d[u]};
        for (int v : G[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                st.push_back(v);
            }
        }
    }
    return best;
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    G.assign(n + 1, {});
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int A = farthest(1).first;
    auto [B, diam] = farthest(A);
    cout << diam << '\n' << A << ' ' << B << '\n';
    return 0;
}

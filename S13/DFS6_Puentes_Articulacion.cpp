/*
 * DFS6 - PUENTES Y PUNTOS DE ARTICULACION (low-link)
 * USO: carretera cuya eliminacion desconecta el grafo (puente) o ciudad cuya
 *      eliminacion lo desconecta (punto de articulacion).
 * INPUT : n m, luego m lineas "u v" (no dirigido; admite aristas repetidas).
 * OUTPUT: cantidad de puentes y los puentes; cantidad de puntos de
 *         articulacion y los puntos.
 * DEFINICION: tin[u] = orden de descubrimiento; low[u] = menor tin alcanzable
 *   desde el subarbol de u usando a lo sumo UNA arista hacia atras.
 *   Puente (u,v) hijo v:   low[v] > tin[u]
 *   Articulacion u:        low[v] >= tin[u] para algun hijo v (u no raiz),
 *                          o u es raiz con mas de 1 hijo.
 * Se guarda el id de la arista para no volver por la misma arista del padre.
 * COMPLEJIDAD: O(n+m)   (recursivo)
 */
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> G;   // {vecino, id arista}
vector<int> tin, low;
vector<char> isArt;
vector<pair<int, int>> bridges;
int T = 0;
void dfs(int u, int pe) {
    tin[u] = low[u] = ++T;
    int children = 0;
    for (auto [v, id] : G[u]) {
        if (id == pe) continue;
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) bridges.push_back({u, v});
            if (low[v] >= tin[u] && pe != -1) isArt[u] = 1;
            ++children;
        }
    }
    if (pe == -1 && children > 1) isArt[u] = 1;
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    G.assign(n + 1, {});
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    isArt.assign(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    for (int i = 1; i <= n; ++i)
        if (!tin[i]) dfs(i, -1);
    cout << bridges.size() << '\n';
    for (auto [a, b] : bridges) cout << a << ' ' << b << '\n';
    vector<int> arts;
    for (int i = 1; i <= n; ++i) if (isArt[i]) arts.push_back(i);
    cout << arts.size() << '\n';
    for (int x : arts) cout << x << ' ';
    cout << '\n';
    return 0;
}

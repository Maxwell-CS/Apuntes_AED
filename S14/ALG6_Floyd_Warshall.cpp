/*
 * ALG6 - FLOYD-WARSHALL (todos los pares)
 * USO: distancia minima entre CUALQUIER par de nodos. Solo si n <= ~400.
 * INPUT : n m, luego m lineas "u v w" (no dirigido), luego q,
 *         luego q lineas "a b" (consultas).
 * OUTPUT: por cada consulta la distancia minima de a a b, o -1.
 * COMPLEJIDAD: O(n^3)
 * Para dirigido: quitar D[v][u] = ...
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> D(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; ++i) D[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        D[u][v] = min(D[u][v], (ll)w);
        D[v][u] = min(D[v][u], (ll)w);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (D[i][k] < INF && D[k][j] < INF)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (D[a][b] >= INF ? -1 : D[a][b]) << '\n';
    }
    return 0;
}

/*
 * ALG1 - DIJKSTRA BASICO + RECONSTRUIR CAMINO
 * USO: menor peso de 1 a n (pesos > 0) y el camino exacto.
 * INPUT : n m, luego m lineas "u v w" (no dirigido). Origen=1, destino=n.
 * OUTPUT: -1 si no hay camino; si hay: distancia y en la sig. linea el camino.
 * COMPLEJIDAD: O((n+m) log n)
 * CLAVES: usar long long, INF = LLONG_MAX/4, P[v] = padre para reconstruir.
 * Para dirigido: quitar la linea G[v].push_back({u,w}).
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<ll> D(n + 1, INF);
    vector<int> P(n + 1, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    D[1] = 0;
    Q.push({0, 1});
    while (!Q.empty()) {
        auto [d, u] = Q.top(); Q.pop();
        if (d != D[u]) continue;
        for (auto [v, w] : G[u]) {
            if (D[v] > d + w) {
                D[v] = d + w;
                P[v] = u;
                Q.push({D[v], v});
            }
        }
    }
    if (D[n] >= INF) { cout << -1 << '\n'; return 0; }
    vector<int> path;
    for (int x = n; x != 0; x = P[x]) path.push_back(x);
    reverse(path.begin(), path.end());
    cout << D[n] << '\n';
    for (int x : path) cout << x << ' ';
    cout << '\n';
    return 0;
}

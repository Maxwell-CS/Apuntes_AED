/*
 * ALG4 - DIJKSTRA CONTANDO CAMINOS MINIMOS
 * USO: cuantos caminos de peso minimo hay de 1 a n, y cuantas aristas
 *      tienen el camino minimo con MENOS y con MAS aristas.
 * INPUT : n m, luego m lineas "u v w" (no dirigido, w >= 1). Origen=1, destino=n.
 * OUTPUT: -1 si no hay camino; si hay:
 *         distancia  cantidad_de_caminos(mod 1e9+7)  min_aristas  max_aristas
 * CLAVES: si nd < D[v] -> reiniciar cnt/mn/mx con los de u.
 *         si nd == D[v] -> sumar cnt, tomar min de mn y max de mx.
 *         (funciona porque w >= 1: u ya esta final al sacarlo de la cola)
 * COMPLEJIDAD: O((n+m) log n)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;
const ll MOD = 1000000007;
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
    vector<ll> D(n + 1, INF), cnt(n + 1, 0);
    vector<int> mn(n + 1, 0), mx(n + 1, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    D[1] = 0; cnt[1] = 1;
    Q.push({0, 1});
    while (!Q.empty()) {
        auto [d, u] = Q.top(); Q.pop();
        if (d != D[u]) continue;
        for (auto [v, w] : G[u]) {
            ll nd = d + w;
            if (nd < D[v]) {
                D[v] = nd;
                cnt[v] = cnt[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                Q.push({nd, v});
            } else if (nd == D[v]) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    }
    if (D[n] >= INF) { cout << -1 << '\n'; return 0; }
    cout << D[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n] << '\n';
    return 0;
}

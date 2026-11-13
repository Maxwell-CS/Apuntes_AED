/*
 * ALG5 - DIJKSTRA CON ESTADO EXTRA (una arista especial / cupon)
 * USO: "puedes usar UNA vez un cupon: una arista cuesta la mitad (o 0)".
 *      Sirve para cualquier "una vez puedo hacer X" (flag usado / no usado).
 * IDEA: 2 pisos. nodo v = cupon sin usar, nodo v+n = cupon ya usado.
 *       Arista normal: mismo piso. Arista con cupon: piso 0 -> piso 1.
 * INPUT : n m, luego m lineas "u v w" (no dirigido). Origen=1, destino=n.
 * OUTPUT: menor peso (siempre llega si hay camino), o -1.
 * CAMBIAR: w / 2  ->  0   si el cupon hace la arista gratis.
 * COMPLEJIDAD: O((n+m) log n)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(2 * n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        for (int f = 0; f < 2; ++f) {            // arista normal en cada piso
            G[u + f * n].push_back({v + f * n, w});
            G[v + f * n].push_back({u + f * n, w});
        }
        G[u].push_back({v + n, w / 2});          // usar cupon
        G[v].push_back({u + n, w / 2});
    }
    vector<ll> D(2 * n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    D[1] = 0;
    Q.push({0, 1});
    while (!Q.empty()) {
        auto [d, u] = Q.top(); Q.pop();
        if (d != D[u]) continue;
        for (auto [v, w] : G[u]) {
            if (D[v] > d + w) {
                D[v] = d + w;
                Q.push({D[v], v});
            }
        }
    }
    ll ans = min(D[n], D[2 * n]);   // con o sin usar cupon
    cout << (ans >= INF ? -1 : ans) << '\n';
    return 0;
}

/*
 * ALG2 - DIJKSTRA CON PARIDAD (numero PAR o IMPAR de aristas)
 * USO: "llegar a n usando una cantidad par/impar de carreteras".
 * IDEA: grafo de 2 pisos. nodo v = (v, par), nodo v+n = (v, impar).
 *       Cada arista cambia de piso.
 * INPUT : n m, luego m lineas "u v w" (no dirigido). Origen=1, destino=n.
 * OUTPUT: menor peso, o -1 si no existe.
 * CAMBIAR: OBJ = 0 (par)  /  OBJ = 1 (impar)
 * COMPLEJIDAD: O((n+m) log n)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;
const int OBJ = 1;   // 0 = par, 1 = impar
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(2 * n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        for (int p = 0; p < 2; ++p) {
            G[u + p * n].push_back({v + (1 - p) * n, w});
            G[v + p * n].push_back({u + (1 - p) * n, w});
        }
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
    ll ans = D[n + OBJ * n];
    cout << (ans >= INF ? -1 : ans) << '\n';
    return 0;
}

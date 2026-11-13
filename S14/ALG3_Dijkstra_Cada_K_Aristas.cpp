/*
 * ALG3 - DIJKSTRA CON "CADA K ARISTAS" (cantidad de aristas = R mod K)
 * USO: "solo puedo parar/devolver tras recorrer un multiplo de K carreteras",
 *      o cantidad de aristas congruente a R modulo K. (K=2 es paridad)
 * IDEA: K pisos. nodo (v, r) = v + r*n  (r = aristas recorridas mod K).
 *       Recorrer una arista lleva de (u,r) a (v,(r+1)%K).
 * INPUT : n m, luego m lineas "u v w" (no dirigido). Origen=1, destino=n.
 * OUTPUT: menor peso, o -1.
 * CAMBIAR: K y R abajo. Memoria: n*K nodos (cuidar que n*K no sea enorme).
 * COMPLEJIDAD: O(K (n+m) log(nK))
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;
const int K = 3;   // modulo
const int R = 0;   // residuo buscado (0 = multiplo de K)
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n * K + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        for (int r = 0; r < K; ++r) {
            int r2 = (r + 1) % K;
            G[u + r * n].push_back({v + r2 * n, w});
            G[v + r * n].push_back({u + r2 * n, w});
        }
    }
    vector<ll> D(n * K + 1, INF);
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
    ll ans = D[n + R * n];
    cout << (ans >= INF ? -1 : ans) << '\n';
    return 0;
}

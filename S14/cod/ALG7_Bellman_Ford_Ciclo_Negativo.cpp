/*
 * ALG7 - BELLMAN-FORD (pesos negativos / ciclo negativo)
 * USO: caminos minimos cuando hay aristas con peso NEGATIVO, o detectar
 *      si hay un ciclo de peso negativo alcanzable desde 1.
 * INPUT : n m, luego m lineas "u v w" (DIRIGIDO, w puede ser negativo). Origen=1.
 * OUTPUT: "CICLO NEGATIVO" si existe uno alcanzable desde 1;
 *         si no, n numeros: distancia de 1 a cada nodo ("INF" si no alcanzable).
 * COMPLEJIDAD: O(n*m)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> E(m);
    for (auto &e : E) cin >> e[0] >> e[1] >> e[2];
    vector<ll> D(n + 1, INF);
    D[1] = 0;
    bool neg = false;
    for (int it = 1; it <= n; ++it) {
        bool changed = false;
        for (auto &e : E) {
            int u = e[0], v = e[1], w = e[2];
            if (D[u] < INF && D[v] > D[u] + w) {
                D[v] = D[u] + w;
                changed = true;
            }
        }
        if (!changed) break;
        if (it == n) neg = true;   // aun relaja en la iteracion n
    }
    if (neg) { cout << "CICLO NEGATIVO\n"; return 0; }
    for (int i = 1; i <= n; ++i) {
        if (D[i] >= INF) cout << "INF ";
        else cout << D[i] << ' ';
    }
    cout << '\n';
    return 0;
}

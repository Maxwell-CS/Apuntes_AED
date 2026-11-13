/*
 * ALG9 - BFS (camino minimo SIN pesos / pesos iguales)
 * USO: menor cantidad de aristas de 1 a n y el camino. Tambien sirve para
 *      grillas o cuando todas las aristas valen 1.
 * INPUT : n m, luego m lineas "u v" (no dirigido). Origen=1, destino=n.
 * OUTPUT: -1 si no hay camino; si hay: cantidad de aristas y el camino.
 * COMPLEJIDAD: O(n+m)
 * (Si hay pesos 0/1: usar deque, push_front para peso 0, push_back para 1.)
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
    vector<int> D(n + 1, -1), P(n + 1, 0);
    queue<int> Q;
    D[1] = 0;
    Q.push(1);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : G[u]) {
            if (D[v] == -1) {
                D[v] = D[u] + 1;
                P[v] = u;
                Q.push(v);
            }
        }
    }
    if (D[n] == -1) { cout << -1 << '\n'; return 0; }
    vector<int> path;
    for (int x = n; x != 0; x = P[x]) path.push_back(x);
    reverse(path.begin(), path.end());
    cout << D[n] << '\n';
    for (int x : path) cout << x << ' ';
    cout << '\n';
    return 0;
}

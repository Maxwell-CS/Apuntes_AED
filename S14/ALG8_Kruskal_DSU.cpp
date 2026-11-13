/*
 * ALG8 - KRUSKAL + DSU (ARBOL DE EXPANSION MINIMA)
 * USO: conectar todas las ciudades con costo total minimo (MST).
 *      El DSU tambien sirve solo para "estan conectados?" / contar componentes.
 * INPUT : n m, luego m lineas "u v w" (no dirigido).
 * OUTPUT: costo total del MST, o -1 si el grafo no es conexo.
 * COMPLEJIDAD: O(m log m)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> par, sz;
int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> E(m);          // {w, u, v}
    for (auto &e : E) cin >> e[1] >> e[2] >> e[0];
    sort(E.begin(), E.end());
    par.resize(n + 1);
    sz.assign(n + 1, 1);
    iota(par.begin(), par.end(), 0);
    ll total = 0;
    int used = 0;
    for (auto &e : E) {
        if (unite(e[1], e[2])) {
            total += e[0];
            ++used;
        }
    }
    cout << (used == n - 1 ? total : -1) << '\n';
    return 0;
}

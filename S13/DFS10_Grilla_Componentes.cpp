/*
 * DFS10 - DFS EN GRILLA (islas / regiones)
 * USO: contar islas, area de la isla mas grande, regiones de '.' o '#'.
 * INPUT : n m, luego n lineas con m caracteres ('.' libre, '#' bloqueado).
 * OUTPUT: cantidad de regiones de '.' y el tamano de la mas grande.
 * CLAVE : dx/dy para los 4 vecinos (agregar diagonales para 8 vecinos).
 *         Se marca la celda al METERLA a la pila (no al sacarla).
 * COMPLEJIDAD: O(n*m)
 */
#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &s : g) cin >> s;
    vector<vector<char>> vis(n, vector<char>(m, 0));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int regions = 0, best = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] != '.' || vis[i][j]) continue;
            ++regions;
            int size = 0;
            vector<pair<int, int>> st = {{i, j}};
            vis[i][j] = 1;
            while (!st.empty()) {
                auto [x, y] = st.back(); st.pop_back();
                ++size;
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (g[nx][ny] != '.' || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    st.push_back({nx, ny});
                }
            }
            best = max(best, size);
        }
    }
    cout << regions << ' ' << best << '\n';
    return 0;
}

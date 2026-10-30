#include<bits/stdc++.h>

using namespace std;


const int df[4] = {-1, 0, 1, 0};
const int dc[4] = { 0, 1, 0,-1};

// estado (f, c, d) -> (f*m + c)*4 + d
int BFS(int n, int m, vector<string> &s) {
    vector<int> dist(4 * n * m, -1);
    queue<int> Q;
    int ini = (0 * m + 0) * 4 + 1;      // casilla (0,0) mirando a la derecha
    dist[ini] = 0;
    Q.emplace(ini);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int d = u % 4;
        int c = (u / 4) % m;
        int f = (u / 4) / m;
        if (f == n - 1 and c == m - 1) return dist[u];  // primer hallazgo = minimo

        for (int nd : {(d + 1) % 4, (d + 3) % 4}) {
            int v = (f * m + c) * 4 + nd;
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            Q.emplace(v);
        }

        int vf = f + df[d];
        int vc = c + dc[d];
        if (vf < 0 or vc < 0 or vf >= n or vc >= m) continue;
        if (s[vf][vc] == '#') continue;
        int v = (vf * m + vc) * 4 + d;
        if (dist[v] != -1) continue;
        dist[v] = dist[u] + 1;
        Q.emplace(v);
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    cout << BFS(n, m, s) << "\n";

    return 0;
}

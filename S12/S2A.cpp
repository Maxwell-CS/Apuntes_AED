#include<bits/stdc++.h>

using namespace std;

pair<int, long long> Componente(int src, vector<bool>& visto, vector<vector<int>>& G) {
    int vertices = 0;
    long long sumaGrados = 0;
    queue<int> Q;
    visto[src] = true;
    Q.emplace(src);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        vertices++;
        sumaGrados += G[u].size();
        for (auto &v : G[u]) {
            if (visto[v]) continue;
            visto[v] = true;
            Q.emplace(v);
        }
    }
    return {vertices, sumaGrados};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<bool> visto(n, false);
    for (int i = 0; i < n; i++) {
        if (visto[i]) continue;
        pair<int, long long> comp = Componente(i, visto, G);
        int vertices = comp.first;
        long long aristas = comp.second / 2;
        if (aristas > vertices) {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "SI" << "\n";
    return 0;
}

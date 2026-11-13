#include<bits/stdc++.h>
using namespace::std;
const long long INF = numeric_limits<long long>::max() / 4;
vector<long long> Dijkstra(int src, int n, vector<vector<pair<int, int>>> &G) {
    vector<long long> D(n+1, INF);
    D[src] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>
    Q;
    Q.emplace(0, src);
    while (not Q.empty()) {
        int u; long long d;
        tie(d, u) = Q.top(); Q.pop();
        if (D[u] != d) continue;
        for (auto &e : G[u]) {
            int v, w;
            tie(v, w) = e;
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                Q.emplace(D[v], v);
            }
        }
    }
    return D;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    // nodo i = ciudad i con paridad par, nodo i+n = ciudad i con paridad impar
    vector<vector<pair<int, int>>> G(2*n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v+n, w);
        G[v+n].emplace_back(u, w);
        G[u+n].emplace_back(v, w);
        G[v].emplace_back(u+n, w);
    }
    vector<long long> D = Dijkstra(1, 2*n, G);
    cout << (D[n] >= INF ? -1 : D[n]) << '\n';
    return 0;
}

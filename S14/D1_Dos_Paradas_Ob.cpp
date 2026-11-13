#include<bits/stdc++.h>
using namespace::std;

const  long long inf = numeric_limits< long long>::max();
vector< long long> Dijkstra( long long src,  long long n, vector<vector<pair< long long,  long long>>> &G) {
    vector< long long> D(n + 1, numeric_limits< long long>::max());
    D[src] = 0;
    priority_queue<pair< long long,  long long>, vector<pair< long long,  long long>>, greater<pair< long long,  long long>>>
    Q;
    Q.emplace(0, src);
    while (not Q.empty()) {
         long long u, d;
        tie(d, u) = Q.top(); Q.pop();
        if (D[u] != d) continue;
        for (auto &e : G[u]) {
             long long v, w;
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
     long long n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<pair< long long,  long long>>> G(n + 1);
    for ( long long i = 0; i < m; ++i) {
         long long u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector< long long> D = Dijkstra(1, n, G);
    vector< long long> D1 = Dijkstra(n, n, G);
    vector< long long> D2 = Dijkstra(a, n, G);
    long long res = inf;
    if (D[a] != inf and D2[b] != inf and D1[b] != inf and D1[a] + D2[b] + D1[b] < res) {
        res = D[a] + D2[b] + D1[b];
    }
    if (D[b] != inf and D2[b] != inf and D1[a] != inf and D1[b] + D2[b] + D1[a] < res) {
        res = D[b] + D2[b] + D1[a];
    }
    if (res == inf) {
        cout << -1;
        return 0;
    }
    cout << res << '\n';
    return 0;
}
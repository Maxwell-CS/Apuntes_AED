#include<bits/stdc++.h>
using namespace::std;
vector< long long> Dijkstra( long long src,  long long n, vector<vector<pair< long long,  long long>>> &G) {
    vector< long long> D(n+1, numeric_limits<long long>::max());
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
     long long n, m;
    cin >> n >> m;
    vector<vector<pair< long long,  long long>>> G(n+1);
    for ( long long i = 0; i < m; ++i) {
         long long u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector< long long> D1 = Dijkstra(1, n, G);
    vector< long long> D2 = Dijkstra(n, n, G);
    long long min_T = numeric_limits<long long>::max();
     long long cnt_min = 0;
    for ( long long i = 1; i<= n; ++i) {
        long long cur_T = max(D1[i], D2[i]);
        if (cur_T < min_T) {
            min_T = cur_T;
            cnt_min = 1;
        }
        else if (cur_T == min_T) {
            ++cnt_min;
        }
    }
    if (min_T == numeric_limits<long long>::max()) {
        cout << -1 << '\n';
    }
    else {
        cout << min_T  << " " << cnt_min << '\n';
    }
    return 0;
}
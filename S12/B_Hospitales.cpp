#include<bits/stdc++.h>

using namespace std;

vector<int> MultisourceBFS(vector<int> & src, int n, vector<vector<int>> & G) {
    vector<int> D(n, -1);
    queue<int> Q;

    for (auto &x : src) {
        D[x] = 0;
        Q.emplace(x);
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto &v : G[u]) {
            if (D[v] != -1) continue;
            D[v] = D[u] + 1;
            Q.emplace(v);
        }
    }
    return D;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m, k;
    cin>>n>>m>>k;
    vector<int> esp(k);
    for ( int i = 0; i < k; i++) {
        cin>>esp[i];
        --esp[i];
    }
    vector<vector<int>> G(n, vector<int>());
    for ( int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        --u; --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> dist = MultisourceBFS(esp, n, G);
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " \n"[i + 1 == n];
    }

    return 0;
}
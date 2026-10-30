#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

bool BipartiteCheck(int src, vector<int>& color, vector<vector<int>>& G) {
    color[src] = 0;
    queue<int> Q;
    Q.emplace(src);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto &v : G[u]) {
            if (color[v] != -1) {
                if (color[v] == color[u]) return false;
                continue;
            }
            color[v] = 1 - color[u];
            Q.emplace(v);
        }
    }
    return true;
}



int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;

    vector<vector<int>> G(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        --u; --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    long long res = 1;
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] != -1) continue;
        if (not BipartiteCheck(i, color, G)) {
            cout<<"NO"<<"\n";
            return 0;
        }
        res = (res*2) % MOD;
    }
    cout<<"SI "<<res<<"\n";
    return 0;
}
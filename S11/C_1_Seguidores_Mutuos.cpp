#include<bits/stdc++.h>

using namespace::std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    unordered_set<long long> aristas;       // clave de (u,v): u*(n+1)+v
    vector<pair<int,int>> edges;
    vector<int> deg_input(n+1,0);

    for (int i=0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        edges.emplace_back(u,v);
        aristas.insert(1ll*u*(n+1) + v);
        deg_input[v]++;
    }

    int couple = 0;
    for (auto &e : edges) {
        int u = e.first, v = e.second;
        if (aristas.count(1ll*v*(n+1) + u)) couple++;   // existe v -> u
    }
    couple /= 2;                                        // cada pareja se contó dos veces

    int best = max_element(deg_input.begin() + 1, deg_input.end()) - deg_input.begin();
    cout<<couple<<" "<<best<<" "<<deg_input[best]<<endl;

    return 0;
}

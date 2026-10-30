#include<bits/stdc++.h>

using namespace::std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<int>> cont(n + 1);
    for(int i=0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        cont[u].push_back(v);
        cont[v].push_back(u);
    }
    for(auto& a : cont) sort(a.begin(), a.end());

    for(int i=0; i < q; i++) {
        int x,u,k;
        cin>>x>>u>>k;
        if (x == 1) {
            if ((int)cont[u].size() < k) {
                cout<<"-1\n";
            }
            else
                cout<<cont[u][k - 1]<<'\n';
        }
        else {
            cout<<upper_bound(cont[u].begin(), cont[u].end(), k) - cont[u].begin()<<'\n';
        }
    }

    return 0;
}

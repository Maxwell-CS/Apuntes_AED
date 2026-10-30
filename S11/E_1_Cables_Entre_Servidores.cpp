#include<bits/stdc++.h>

using namespace::std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
    int n,m,q;
    cin>>n>>m>>q;

    map<vector<int>, int> serv;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        serv[{min(u,v), max(u,v)}] += 1;
    }
    for (int i = 0; i < q; i++) {
        int u,v;
        cin>>u>>v;
        cout<<serv[{min(u,v), max(u,v)}]<<"\n";
    }

    return 0;
}

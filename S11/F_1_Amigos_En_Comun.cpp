#include<bits/stdc++.h>

using namespace::std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<int>> fr(n+1, vector<int> ());
    map<vector<int>, int> fc;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        fr[u].push_back(v);
        fr[v].push_back(u);
    }
    vector<bool> cont(n+1, false);
    for (int i = 0; i < q; i++) {
        int u,v, res = 0;
        cin>>u>>v;
        for (auto x : fr[u]) {
            cont[x] = true;
        }
        for (auto x : fr[v]) {
            if (cont[x]) {
                res ++;
            }
        }
        cout<<res<<"\n";
        for (int x : fr[u]) {
            cont[x] = false;
        }
    }

    return 0;
}

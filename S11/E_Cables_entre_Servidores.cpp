#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n,m,q;

    cin>>n>>m>>q;

    map<pair<int,int>,int> frec;
    for(int i = 1; i <= m; i++) {
        int x,y;
        cin>>x>>y;
        if (x>y) swap(x,y);
        ++frec[make_pair(x,y)];

    }
    while (q--) {
        int x,y;
        cin>>x>>y;
        if (x>y) swap(x,y);
        cout<<(frec.count(make_pair(x,y)) ? frec[make_pair(x,y)]: 0)<<"\n";
    }

    return 0;
}
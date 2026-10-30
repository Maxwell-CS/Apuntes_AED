#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        ++deg[u-1];
        ++deg[v-1];
    }
    int cant_impar = 0;
    for (int i = 0; i < deg.size(); i++) {
        if (deg[i]%2 != 0) {
            cant_impar++;
        }
    }

    if (cant_impar == 0) {
        cout<<"CIRCUITO"<<endl;
    }
    else if (cant_impar == 2) {
        cout<<"CAMINO"<<endl;
    }
    else {
        cout<<"IMPOSIBLE"<<endl;
    }
    return 0;
}

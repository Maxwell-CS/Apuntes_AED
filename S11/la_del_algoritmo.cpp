#include<bits/stdc++.h>

using namespace::std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    vector<vector<int>> ady(n + 1);
    vector<int> grado(n + 1, 0);

    for(int i=0; i < m; i++) {
        int a,b;
        cin>>a>>b;

        ady[a].push_back(b);
        ady[b].push_back(a);
        grado[a]++;
        grado[b]++;
    }

    // un camino simple tiene exactamente n-1 aristas
    if(m != n - 1) {
        cout<<"NO"<<"\n";
        return 0;
    }

    // y ningun nodo con mas de 2 vecinos
    for(int i=1; i <= n; i++) {
        if(grado[i] > 2) {
            cout<<"NO"<<"\n";
            return 0;
        }
    }

    // recorrido iterativo con pila para comprobar conectividad
    vector<char> visto(n + 1, 0);
    stack<int> pila;
    pila.push(1);
    visto[1] = 1;
    int alcanzados = 0;

    while(!pila.empty()) {
        int actual = pila.top();
        pila.pop();
        alcanzados++;
        for(int vecino : ady[actual]) {
            if(!visto[vecino]) {
                visto[vecino] = 1;
                pila.push(vecino);
            }
        }
    }

    cout<<(alcanzados == n ? "SI" : "NO")<<"\n";
    return 0;
}

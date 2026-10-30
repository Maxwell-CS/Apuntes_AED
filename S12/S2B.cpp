#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int N, D, k;
    cin >> N >> D >> k;

    vector<int> destino(N + 1);
    for (int i = 1; i <= N; i++) destino[i] = i;    // casilla normal: te quedas en ella
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        destino[a] = b;                              // escalera o serpiente: caes en b
    }

    vector<int> dist(N + 1, -1);
    queue<int> Q;
    dist[1] = 0;
    Q.emplace(1);
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int d = 1; d <= D; d++) {
            if (x + d > N) break;                    // no se puede pasar de N
            int v = destino[x + d];
            if (dist[v] != -1) continue;
            dist[v] = dist[x] + 1;
            Q.emplace(v);
        }
    }
    cout << dist[N] << "\n";
    return 0;
}

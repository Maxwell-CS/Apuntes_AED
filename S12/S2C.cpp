#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int w;
    string s, t;
    cin >> w >> s >> t;

    int total = 1;                                  // 10^w codigos posibles
    for (int i = 0; i < w; i++) total *= 10;

    int k;
    cin >> k;
    vector<bool> prohibido(total, false);
    for (int i = 0; i < k; i++) {
        string p;
        cin >> p;
        prohibido[stoi(p)] = true;                  // "0042" -> 42
    }

    int src = stoi(s), dst = stoi(t);
    if (prohibido[src] or prohibido[dst]) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> dist(total, -1);
    queue<int> Q;
    dist[src] = 0;
    Q.emplace(src);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int pot = 1;                                // 10^rueda
        for (int r = 0; r < w; r++) {
            int digito = (u / pot) % 10;
            for (int nuevo : {(digito + 1) % 10, (digito + 9) % 10}) {   // subir / bajar
                int v = u + (nuevo - digito) * pot;                      // cambia solo esa rueda
                if (prohibido[v] or dist[v] != -1) continue;
                dist[v] = dist[u] + 1;
                Q.emplace(v);
            }
            pot *= 10;
        }
    }
    cout << dist[dst] << "\n";
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

// BFS 0-1: entrar a una casilla libre cuesta 0, entrar a una pared cuesta 1
int BFS01(int sx, int sy, int tx, int ty, int n, int m, vector<string> &s) {
    const int INF = 1e9;
    vector<int> dx = {1,-1, 0, 0};
    vector<int> dy = {0, 0, 1,-1};
    vector<vector<int>> d(n, vector<int>(m, INF));
    deque<pair<int, int>> D;
    D.emplace_back(sx, sy);
    d[sx][sy] = 0;
    while (!D.empty()) {
        int ux, uy;
        tie(ux, uy) = D.front();
        D.pop_front();
        for (int k = 0; k < 4; k++) {
            int vx = ux + dx[k];
            int vy = uy + dy[k];
            if ( vx < 0 or vy < 0 or vx >= n or vy >= m) continue;
            int w = (s[vx][vy] == '#') ? 1 : 0;
            if (d[ux][uy] + w < d[vx][vy]) {
                d[vx][vy] = d[ux][uy] + w;
                if (w == 0) D.emplace_front(vx, vy);
                else D.emplace_back(vx, vy);
            }
        }
    }
    return d[tx][ty];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for ( int i =0; i<n; i++) {
        cin>>s[i];
    }
    cout << BFS01(0, 0, n - 1, m - 1, n, m, s)<<"\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 9;

char s[N][N+1];
bool row_values[N][N+1];
bool col_values[N][N+1];
bool box_values[N][N+1];

void solve(int x, int y) {
    if (x == N) {
        for (int i = 0; i < N; i++) {
            cout << s[i] << "\n";
        }
        exit(0);
    }
    if (y == N) {
        solve(x + 1, 0);
        return;
    }
    if (s[x][y] != '.') {
        solve(x, y + 1);
        return;
    }

    int b = (x / 3) * 3 + y / 3;
    for (int v = 1; v <= N; v++) {
        if (row_values[x][v] || col_values[y][v] || box_values[b][v]) continue;

        s[x][y] = '0' + v;
        row_values[x][v] = col_values[y][v] = box_values[b][v] = true;

        solve(x, y + 1);

        row_values[x][v] = col_values[y][v] = box_values[b][v] = false;
        s[x][y] = '.';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < N; j++) {
            if (s[i][j] == '.') continue;
            int v = s[i][j] - '0';
            int b = (i / 3) * 3 + j / 3;
            row_values[i][v] = col_values[j][v] = box_values[b][v] = true;
        }
    }

    solve(0, 0);
}

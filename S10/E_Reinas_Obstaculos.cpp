#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> tablero;
bool col[20], diag1[40], diag2[40]; // columna, r-c+(n-1), r+c

int contar(int r) {
    if (r == n) return 1;

    int total = 0;
    for (int c = 0; c < n; c++) {
        if (tablero[r][c] == '#') continue;
        if (col[c]) continue;
        if (diag1[r - c + n - 1]) continue;
        if (diag2[r + c]) continue;

        col[c] = diag1[r - c + n - 1] = diag2[r + c] = true;
        total += contar(r + 1);
        col[c] = diag1[r - c + n - 1] = diag2[r + c] = false;
    }
    return total;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    tablero.resize(n);
    for (int i = 0; i < n; i++) cin >> tablero[i];
    cout << contar(0) << "\n";
    return 0;
}

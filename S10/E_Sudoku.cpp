#include <bits/stdc++.h>
using namespace std;

const int N = 9;


char s[N][N+1];
bool col_values[N][N+1];
bool row_values[N][N+1];
bool candidate[N][N][N+1];

void solve(int x, int y) {
    if (x == N) {
        for (int i = 0; i < N; i++) {
            cout << s[i] << " ";
        }
        exit(0);
    }
    if (y == N) solve

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int i; i < N; i++) {
        cin>> s[i];
        for (int j = 0; j < N; j++) {
            fill_n(candidate[i][j], N+1, true);
        }
    }
}

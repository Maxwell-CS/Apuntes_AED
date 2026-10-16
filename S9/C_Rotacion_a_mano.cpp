#include<bits/stdc++.h>
using namespace::std;

const int MAXN = 200005;
int L[MAXN], R[MAXN], P[MAXN];
int root = 1;

void reemplazar_en_padre(int x, int y) {
    int p = P[x];
    P[y] = p;
    if (p == 0) root = y;
    else if (L[p] == x) L[p] = y;
    else R[p] = y;
}

void rotate_left(int x) {
    int y = R[x];
    reemplazar_en_padre(x, y);
    R[x] = L[y];
    if (L[y]) P[L[y]] = x;
    L[y] = x;
    P[x] = y;
}

void rotate_right(int x) {
    int y = L[x];
    reemplazar_en_padre(x, y);
    L[x] = R[y];
    if (R[y]) P[R[y]] = x;
    R[y] = x;
    P[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> L[i] >> R[i];
        if (L[i] != 0) P[L[i]] = i;
        if (R[i] != 0) P[R[i]] = i;
    }

    for (int i = 0; i < q; ++i) {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'I') rotate_left(x);
        else rotate_right(x);
    }

    cout << root << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << L[i] << " " << R[i] << "\n";
    }
    return 0;
}

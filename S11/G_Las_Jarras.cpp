#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int A, B, x, y;
    cin >> A >> B >> x >> y;

    long long e = 0, ind = 0;
    for (int a = 0; a <= A; a++) {
        for (int b = 0; b <= B; b++) {
            int t1 = min(a, B - b);   // a -> b
            int t2 = min(b, A - a);   // b -> a
            pair<int,int> mv[6] = {
                {A, b}, {a, B},
                {0, b}, {a, 0},
                {a - t1, b + t1},
                {a + t2, b - t2}
            };
            sort(mv, mv + 6);
            for (int i = 0; i < 6; i++) {
                if (i > 0 && mv[i] == mv[i - 1]) continue;
                if (mv[i] == make_pair(a, b)) continue;
                e++;
                if (mv[i] == make_pair(x, y)) ind++;
            }
        }
    }
    cout << e << " " << ind << "\n";
}

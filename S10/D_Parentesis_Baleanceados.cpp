#include <bits/stdc++.h>
using namespace std;
int n;

void f(string s, int a, int b) {
    if (a == n && b == n) {
        cout << s << "\n";
        return;
    }
    if (a < n) {
        f(s + "(", a+1, b);
    };
    if (b < a) {
        f(s + ")", a, b+1);
    };
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    f("", 0, 0);
}
#include <bits/stdc++.h>
using namespace std;

int i = 0;
vector<string> v;

long long f() {
    string s = v[i++];
    if (s == "*") {
        return f() * f();
    }
    if (s == "+") {
        return f() + f();
    }
    if (s == "-") {
        return f() - f();
    }
    return stoll(s);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    v.resize(n);
    for (int k = 0; k < n; k++) {
        cin >> v[k];
    }
    cout << f() << "\n";
    return 0;
}

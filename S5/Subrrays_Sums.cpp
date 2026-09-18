# include <bits/stdc++.h>

using  namespace std;

template<typename key_type, typename value_type>
struct my_map {
    int m;
    vector<vector<pair<key_type, value_type>>> chains;
    my_map(int m) : m(m) {
        chains.resize(m);
    }
    value_type& operator [] (const key_type &key) {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() and chains[chain_position]
        [at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            chains[chain_position].emplace_back(key, value_type());
        }
        return chains[chain_position][at].second;
    }
    bool has_key (const key_type &key) const {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() and chains[chain_position]
        [at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            return false;
        }
        return true;
    }
    int _hash(key_type key) const {
        uint64_t h = std::hash<key_type>{}(key);
        h += 0x9e3779b97f4a7c15ULL;
        h = (h ^ (h >> 30)) * 0xbf58476d1ce4e5b9ULL;
        h = (h ^ (h >> 27)) * 0x94d049bb133111ebULL;
        h = h ^ (h >> 31);
        return h % m;
    }

    int size() const {
        int total_size = 0;
        for (int i = 0; i < m; ++i) {
            total_size += chains[i].size();
        }
        return total_size;
    }

    void print() {
        for (int i = 0; i < m; ++i) {
            cout << "Bucket " << i << ": " << endl;
            for (auto &e : chains[i]) {
                cout << e.first << " --> " << e.second << endl;
            }
            cout << "End bucket" << endl;
        }
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long n,q;
    cin >> n >>q;
    my_map<long long, long long> elementos(2*n);
    elementos[0] = 1;

    long long sum = 0;
    long long sub = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum+=x;


        sub += elementos[sum-q];

        ++elementos[sum];
    }
    cout << sub << endl;

    return 0;
}


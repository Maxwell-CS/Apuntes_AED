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
    int _hash(key_type key) const  {
        // Para enteros
        const int B = 311;
        const int MOD = 1e9 + 7;
        int hash_value = 0;
        while (key > 0) {
            int d = key % 10;
            hash_value = (1ll * hash_value * B + (d + 1)) % MOD;
            key /= 10;
        }
        return hash_value % m;
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

    int size() const {
        int total_size = 0;
        for (int i = 0; i < m; ++i) {
            total_size += chains[i].size();
        }
        return total_size;
    }

    void delete_k( const key_type &key){
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() and chains[chain_position]
        [at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            return;
        }
        chains[chain_position].erase(chains[chain_position].begin() + at);
    }
};



int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string x;
    cin >> x;
    my_map<int, long long> frecuencia(2*x.size());
    for (long long i = 0; i < x.length(); ++i) {
        ++frecuencia[x[i]];
    }

    string y;
    cin >> y;

    for (long long i = 0; i < y.length(); ++i) {

        if (frecuencia.has_key(y[i])) {
            if (frecuencia[y[i]] > 0) {
                --frecuencia[y[i]];
                if (frecuencia[y[i]] == 0) {
                    frecuencia.delete_k(y[i]);
                }
            }
        }
    }

    if (frecuencia.size() == 0) {
        cout<<"SI";
        return 0;
    }
    cout << "NO";
    return 0;

}
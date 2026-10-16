#include<bits/stdc++.h>
using namespace::std;

template<typename data_type>
struct AVL {

    struct TreeNode {
        int height;
        data_type data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(data_type data = data_type(), int height = 0,
                    TreeNode* left = nullptr,
                    TreeNode* right = nullptr) :
                    data(data), height(height), left(left), right(right) {}
    };

    TreeNode* root;
    int rotations;

    AVL() {
        root = nullptr;
        rotations = 0;
    }

    void update(TreeNode* u) {
        u -> height = 1 + max(h(u -> left) , h(u -> right));
    }

    int h(TreeNode* u) {
        return u == nullptr ? -1 : u -> height;
    }

    int FB(TreeNode* u) {
        return h(u -> left) - h(u -> right);
    }
    TreeNode* search(int key) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->data[0] <= key and key < current->data[1]) {
                return current;
            }
            if (current -> data[0] > key) {
                current = current -> left;
            }
            else {
                current = current -> right;
            }
        }
        return nullptr;
    }

    TreeNode* min_element(TreeNode* u) {
        if (u == nullptr) return nullptr;
        TreeNode* current = u;
        while (current -> left != nullptr) {
            current = current -> left;
        }
        return current;
    }

    TreeNode* rotate_left(TreeNode* u) {
        ++rotations;
        TreeNode* v = u -> right;
        u -> right = v -> left;
        v -> left = u;
        update(u);
        update(v);
        return v;
    }

    TreeNode* rotate_right(TreeNode* u) {
        ++rotations;
        TreeNode* v = u -> left;
        u -> left = v -> right;
        v -> right = u;
        update(u);
        update(v);
        return v;
    }

    TreeNode* rebalance(TreeNode* u) {
        update(u);
        if (FB(u) > 1) {
            // L
            if (FB(u -> left) < 0) {
                // LR
                u -> left = rotate_left(u -> left);
            }
            return rotate_right(u);
        }
        if (FB(u) < -1) {
            // R
            if (FB(u -> right) > 0) {
                // RL
                u -> right = rotate_right(u -> right);
            }
            return rotate_left(u);
        }
        return u;
    }

    bool exists(data_type key) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (key[1] <= current -> data[0]) current = current -> left;
            else if (key[0] >= current -> data[1]) current = current -> right;
            else return true;
        }
        return false;
    }

    TreeNode* insert(TreeNode* u, data_type value) {
        if (u == nullptr) {
            return new TreeNode(value, 0);
        }
        if (value[1] <= u -> data[0]) {
            u -> left = insert(u -> left, value);
        }
        else {
            u -> right = insert(u -> right, value);
        }
        return rebalance(u);
    }

    void insert(data_type value) {
        root = insert(root, value);
    }

    TreeNode* erase(TreeNode* u, int key) {
        if (u == nullptr) return nullptr;
        if (key < u -> data[0]) {
            u -> left = erase(u -> left, key);
        }
        else if (key > u -> data[0]) {
            u -> right = erase(u -> right, key);
        }
        else {
            if (u -> left == nullptr || u -> right == nullptr) {
                TreeNode* child = (u -> left != nullptr) ? u -> left : u -> right;
                delete u;
                return child;
            }
            TreeNode* succ = min_element(u -> right);
            u -> data = succ -> data;
            u -> right = erase(u -> right, u -> data[0]);
        }
        return rebalance(u);
    }

    void erase(int key) {
        root = erase(root, key);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    AVL<vector<int>> T;
    while (q--) {
        int op, x, y;
        cin >> op;
        vector<int> v(2);
        if (op == 1) {
            cin >> x >> y;
            v = {x,y};
            if (T.exists(v)) {
                cout << "NO" << "\n";
            }
            else {
                T.insert(v);
                cout << "SI" << "\n";
            }
        }
        else if (op == 2) {
            cin >> x;
            T.erase(x);
        }
        else if (op == 3) {
            cin >> x;
            auto ser = T.search(x);
            if (ser != nullptr) {
                cout << ser->data[0]<<" "<< ser->data[1]<< "\n";
            }
            else {
                cout << "LIBRE" << "\n";
            }
        }
    }
    return 0;
}

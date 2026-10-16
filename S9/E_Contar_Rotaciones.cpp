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

    TreeNode* insert(TreeNode* u, data_type value) {
        if (u == nullptr) {
            return new TreeNode(value, 0);
        }
        if (value < u -> data) {
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

    TreeNode* erase(TreeNode* u, data_type key) {
        if (u == nullptr) return nullptr;
        if (key < u -> data) {
            u -> left = erase(u -> left, key);
        }
        else if (key > u -> data) {
            u -> right = erase(u -> right, key);
        }
        else {
            if (u -> left == nullptr || u -> right == nullptr) {
                // hoja o un solo hijo
                TreeNode* child = (u -> left != nullptr) ? u -> left : u -> right;
                delete u;
                return child;
            }
            // dos hijos: toma la clave del sucesor y lo elimina del subarbol derecho
            TreeNode* succ = min_element(u -> right);
            u -> data = succ -> data;
            u -> right = erase(u -> right, succ -> data);
        }
        return rebalance(u);
    }

    void erase(data_type key) {
        root = erase(root, key);
    }

    TreeNode* successor (TreeNode* u) {
        if (u -> right != nullptr) {
            TreeNode* succ = min_element(u -> right);
            return succ;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    AVL<int> T;
    while (q--) {
        int op, x;
        cin >> op >> x;
        T.rotations = 0;
        if (op == 1) T.insert(x);
        else T.erase(x);
        cout << T.rotations << " " << T.h(T.root) << '\n';
    }
    return 0;
}

#pragma once

template<typename T1, typename T2>
struct MapSWEA {
    struct Node {
        T1 key;
        T2 value;
        Node* left, * right;
    };
    struct Pair { T1 first; T2 second; };
    Node* root;

    Node* insertRec(Node* node, const T1& key, const T2& value) {
        if (node == nullptr) return new Node{ key, value, nullptr, nullptr };

        if (key < node->key)
            node->left = insertRec(node->left, key, value);
        else if (key > node->key)
            node->right = insertRec(node->right, key, value);
        else
            node->value = value;

        return node;
    }

    void emplace(const T1& key, const T2& value) {
        root = insertRec(root, key, value);
    }

    Node* findRec(Node* node, const T1& key) {
        if (node == nullptr) return nullptr;
        if (key == node->key)
            return node;
        if (key < node->key)
            return findRec(node->left, key);
        else if (node->key < key)
            return findRec(node->right, key);
    }

    Pair* find(const T1& key) {
        auto node = findRec(root, key);
        return (node == nullptr) ? nullptr : new Pair{ node->key, node->value };
    }
    Pair* end() { return nullptr; }

    Node* minValueNode(Node* node) {
        Node* root = node;

        while (root->left != nullptr)
            root = root->left;

        return root;
    }

    Node* eraseRec(Node* node, const T1& key) {
        if (node == nullptr)
            return node;

        if (key < node->key)
            node->left = eraseRec(node->left, key);
        else if (key > node->key)
            node->right = eraseRec(node->right, key);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = eraseRec(node->right, temp->key);
        }
        return node;
    }

    void erase(const T1& key) {
        root = eraseRec(root, key);
    }

    void clearRec(Node* node) {
        if (node == nullptr) return;
        clearRec(node->left);
        clearRec(node->right);
        delete node;
    }

    void clear() { clearRec(root); root = nullptr; }

    T2& operator[](const T1& key) {
        auto res = find(key);
        if (res == end()) { emplace(key, {}); res = find(key); }
        return res->second;
    }
};
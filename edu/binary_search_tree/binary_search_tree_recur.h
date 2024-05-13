#pragma once

template<typename T>
struct BinarySearchTreeRecur {
    struct Node {
        T data;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* root;

    Node* clearRecur(Node* cur) {
        if (cur == nullptr) return nullptr;
        cur->left = clearRecur(cur->left);
        cur->right = clearRecur(cur->right);
        delete cur;
        return nullptr;
    }
    Node* insertRecur(Node* cur, const T& data) {}
    Node* findRecur(Node* cur, const T& data) {}
    Node* eraseRecur(Node* cur, const T& data) {}

    // Implementation
    void clear() { root = clearRecur(root); }
    void insert(const T& data) { root = insertRecur(root, data); }
    Node* find(const T& data) { return findRecur(root, data); }
    void erase(const T& data) { root = eraseRecur(root, data); }
};
#pragma once

template<typename T>
struct BinarySearchTreeIter {
    struct Node {
        T data;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* root;

    void clear() {
        while ()
    }
    void insert(const T& data) {}
    Node* find(const T& data) {}
    void erase(const T& data) {}
};
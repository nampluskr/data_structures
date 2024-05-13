#pragma once

template<typename T>
struct BinarySearchTreeIter {
    struct Node {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
    };
    Node* root;

    void clear() {
        while ()
    }
    void insert(const T& data) {}
    Node* find(const T& data) {}
    void erase(const T& data) {}
};
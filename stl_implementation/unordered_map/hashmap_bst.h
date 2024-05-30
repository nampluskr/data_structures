#pragma once

#include<malloc.h>

template<typename T>
struct BinarySearchTree {
    struct Node {
        T key;
        Node *left, *right;
    };
    Node *root = nullptr;

    Node *newNode(const T& item) {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    Node *insertRec(Node *node, const T& key) {
        if (node == NULL)
            return newNode(key);

        if (key < node->key)
            node->left = insertRec(node->left, key);
        else if (node->key < key)
            node->right = insertRec(node->right, key);

        return node;
    }

    void insert(const T& key) {
        root = insertRec(root, key);
    }

    Node* findRec(Node *node, const T& key) {
        if (node != NULL) {
            if (key == node->key)
                return node;
            if (key < node->key)
                findRec(node->left, key);
            else
                findRec(node->right, key);
        }
        return NULL;
    }

    Node* find(const T& key) {
        return findRec(root, key);
    }

    Node *minValueNode(Node *node) {
        Node *root = node;

        while (root->left != NULL)
            root = root->left;

        return root;
    }

    Node *eraseRec(Node *node, const T& key) {
        if (node == NULL)
            return node;

        if (key < node->key)
            node->left = eraseRec(node->left, key);
        else if (node->key < key )
            node->right = eraseRec(node->right, key);
        else {
            if (node->left == NULL) {
                Node *temp = node->right;
                free(node);
                return temp;
            }
            else if (node->right == NULL) {
                Node *temp = node->left;
                free(node);
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = eraseRec(node->right, temp->key);
        }
        return node;
    }

    void erase(const T& key) {
        root = eraseRec(root, key);
    }

    Node* clearRec(Node* node) {
        if (node == NULL) return nullptr;
        node->left = clearRec(node->left);
        node->right = clearRec(node->right);
        free(node);
        return nullptr;
    }

    void clear() { 
        root = clearRec(root);
    }
};

#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<typename T1, typename T2>
struct HashMapBST {
    struct Pair {
        T1 first;
        T2 second;
        bool operator==(const Pair& pair) const { return first == pair.first; }
        bool operator<(const Pair& pair) const { return first < pair.first; }
    };
    BinarySearchTree<Pair> table[MAX_TABLE];

    void clear() {
        for (int i = 0; i < MAX_TABLE; i++)
            table[i].clear();
    }
    void emplace(const T1& key, const T2& value) {
        int h = hashfunc(key);
        table[h].insert({ key, value });
    }
    void insert(const Pair& pair) {
        emplace(pair.first, pair.second);
    }
    Pair* find(const T1& key) {
        int h = hashfunc(key);
        auto res = table[h].find({ key, {} });
        return &res->key;
    }
    Pair* end() { return nullptr; }
    void erase(const T1& key) {
        int h = hashfunc(key);
        table[h].erase({ key, {} });
    }
    T2& operator[](const T1& key) {
        auto res = find(key);
        if (res == end()) { emplace(key, {}); res = find(key); }
        return res->second;
    }
};
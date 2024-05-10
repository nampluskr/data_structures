#pragma once

#include<malloc.h>

template<typename T>
struct Set {
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
        else if (key > node->key)
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
        else if (key > node->key)
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

    void clearRec(Node* node) {
        if (node == NULL) return;
        clearRec(node->left);
        clearRec(node->right);
        free(node);
    }

    void clear() { 
        clearRec(root);
        root = nullptr;
    }
};
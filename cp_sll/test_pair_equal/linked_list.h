#pragma once

template<typename T>
struct LinkedList {
    struct Node {
        T data;
        Node* next = nullptr;
    };
    Node* head = nullptr;
    Node* tail = nullptr;

    void push_back(const T& data) {
        Node* node = new Node{ data, nullptr };
        if (head == nullptr ) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    Node* find(const T& data) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == data) return cur;
            cur = cur->next;
        }
        return nullptr;
    }
    void erase(const T& data) {
        Node* prev = nullptr;
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == data) break;
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) return;
        if (prev == nullptr) head = cur->next;
        else prev->next = cur->next;
        if (tail == cur) tail = prev;
        if (head == nullptr) tail = nullptr;
        delete cur;
    }

};
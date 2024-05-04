#pragma once

// Reference Linked List Code:
template<typename T>
struct LinkedList {
    struct Node {
        T data;
        Node* next = nullptr;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int cnt = 0;

    void clear() {
        while (!empty()) pop_front();
        cnt = 0;
    }
    void push_back(const T& data) {
        Node* node = new Node{ data, nullptr };
        if (head == nullptr) { head = tail = node; }
        else { tail->next = node; tail = node; }
        cnt++;
    }
    void push_front(const T& data) {
        Node* node = new Node{ data, nullptr };
        if (head == nullptr) { head = tail = node; }
        else { node->next = head; head = node; }
        cnt++;
    }
    void pop_front() {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
        cnt--;
    }
    Node* find(const T& data) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == data) return cur;
            cur = cur->data;
        }
        return nullptr;
    }
    T front() { return head->data; }
    T back() { return tail->data; }
    bool empty() { return head == nullptr; }
    int size() { return cnt; }
};
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
        while (head != nullptr) {
            Node* cur = head;
            head = head->next;
            delete cur; cnt--;
        }
        tail = nullptr;
        // while (!empty()) pop_front();
        // cnt = 0;
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
        Node* cur = head;
        head = head->next;
        delete cur; cnt--;
        if (head == nullptr) tail = nullptr;
    }
    T front() { return head->data; }
    T back() { return tail->data; }
    bool empty() { return head == nullptr; }
    int size() { return cnt; }

    Node* find(const T& data) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == data) return cur;
            cur = cur->data;
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
        if (prev == nullptr) { head = cur->next; }
        else { prev->next = cur->next; }
        delete cur; cnt--;
        if (head == nullptr) tail = nullptr;
    }
};
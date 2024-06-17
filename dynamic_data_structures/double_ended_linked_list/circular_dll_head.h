#pragma once

// https://www.geeksforgeeks.org/insertion-in-doubly-circular-linked-list/
// https://www.geeksforgeeks.org/deletion-in-doubly-circular-linked-list/

template<typename T>
struct CircularDLLHead {
    struct Node {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
    };
    Node* head = nullptr;
    int cnt = 0;

    void clear() {
        while (!empty()) pop_front();
    }
    void push_front(const T& data) {
        Node* node = new Node{ data, nullptr, nullptr };
        if (head == nullptr) {
            node->prev = node->next = node;
            head = node;
        }
        else {
            Node* tail = head->prev;
            node->next = head;
            node->prev = tail;
            tail->next = head->prev = node;
            head = node;
        }
        cnt++;
    }
    void pop_front() {
        Node* temp = head;
        if (head == head->prev) head = nullptr;
        else {
            Node* tail = head->prev;
            head = head->next;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
        cnt--;
    }
    void push_back(const T& data) {
        Node* node = new Node{ data, nullptr, nullptr };
        if (head == nullptr) {
            node->prev = node->next = node;
            head = node;
        }
        else {
            Node* tail = head->prev;
            node->next = head;
            head->prev = node;
            node->prev = tail;
            tail->next = node;
        }
        cnt++;
    }
    void pop_back() {
        Node* temp = head->prev;
        if (head == head->prev) head = nullptr;
        else {
            Node* tail = head->prev->prev;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
        cnt--;
    }
    T front() { return head->data; }
    T back() { return head->prev->data; }
    bool empty() { return head == nullptr; }
    int size() { return cnt; }
};

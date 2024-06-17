#pragma once

// https://www.geeksforgeeks.org/insertion-in-doubly-circular-linked-list/
// https://www.geeksforgeeks.org/deletion-in-doubly-circular-linked-list/

template<typename T>
struct CircularDLLDummy {
    struct Node {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
    };
    Node* head;
    int cnt;

    CircularDLLDummy() { 
        Node* node = new Node{ {}, nullptr, nullptr};
        node->next = node->prev = node;
        head = node;
        cnt = 0;
    }
    ~CircularDLLDummy() { delete head; head = nullptr; }

    void clear() {
        while (!empty()) pop_front();
    }
    void push_front(const T& data) {
        Node* next = head->next;
        Node* node = new Node{ data, nullptr, nullptr };
        head->next = node;
        node->prev = head;
        node->next = next;
        next->prev = node;
        cnt++;
    }
    void pop_front() {
        Node* temp = head->next;
        Node* next = head->next->next;
        head->next = next;
        next->prev = head;
        delete temp;
        cnt--;
    }
    void push_back(const T& data) {
        Node* node = new Node{ data, nullptr, nullptr };
        Node* tail = head->prev;
        node->next = head;
        head->prev = node;
        node->prev = tail;
        tail->next = node;
        cnt++;
    }
    void pop_back() {
        Node* temp = head->prev;
        Node* tail = head->prev->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
        cnt--;
    }
    T front() { return head->next->data; }
    T back() { return head->prev->data; }
    bool empty() { return cnt == 0; }
    int size() { return cnt; }
};

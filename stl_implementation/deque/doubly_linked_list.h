#pragma once

// https://www.geeksforgeeks.org/implementation-deque-using-doubly-linked-list/
template<typename T>
struct DoublyLinkedList {
    struct Node {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
    };
    Node* head = nullptr;
    Node* tail = nullptr;

    void clear() {
        tail = nullptr;
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push_front(const T& data) {
        Node* node = new Node{ data, nullptr, nullptr };
        if (head == nullptr) { head = tail = node; }
        else { node->next = head; head->prev = node; head = node; }
    }
    void push_back(const T& data) {
        Node* node = new Node{ data, nullptr, nullptr };
        if (tail == nullptr) { head = tail = node; }
        else { node->prev = tail; tail->next = node; tail = node; }
    }
    void pop_front() {
        Node* temp = head;
        head = head->next;
        if (head == nullptr) { head = nullptr; }
        else { head->prev = nullptr; }
        delete temp;
    }
    void pop_back() {
        Node* temp = tail;
        tail = tail->prev;
        if (tail == nullptr) { head = nullptr; }
        else { tail->next = nullptr; }
        delete temp;
    }
    T front() { return head->data; }
    T back() { return tail->data; }
    bool empty() { return head == nullptr; }
};
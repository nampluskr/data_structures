#pragma once

template<typename T>
struct CircularDLLHead {
    struct Node {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
    };
    Node* head = nullptr;
    // Node* tail = nullptr;

    void clear() {
        // tail = nullptr;
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push_front(const T& data) {
        Node* node = new Node{ data, nullptr, nullptr };
        if (head == nullptr) { head = node; }
        else { 
            node->next = head; node->prev = head->prev;
            head->prev = node; head = node; }
    }
    void push_back(const T& data) {
        Node* node = new Node{ data, nullptr, nullptr };
        if (head == nullptr) { head = node; }
        else { 
            node->prev = head->prev; node->next = head;
            head->prev->next = node; head->prev = node;
        }
    }
    void pop_front() {
        Node* temp = head;
        head = head->next;
        if (head == nullptr) { head = nullptr; }
        else { head->prev = temp->prev; }
        delete temp;
    }
    void pop_back() {
        Node* temp = head->prev;
        head->prev = head->prev->prev;
        if (head->prev == nullptr) { head = nullptr; }
        else { head->prev->next = head; }
        delete temp;
    }
    T front() { return head->data; }
    T back() { return head->prev->data; }
    bool empty() { return head == nullptr; }
};
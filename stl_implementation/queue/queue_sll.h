#pragma once

template<typename T>
struct QueueSLL {
    struct Node {
        T data;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;

    void clear() { 
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
    void push(const T& data) {
        Node* node = new Node{ data, nullptr };
        if (head == nullptr) { head = tail = node; }
        else { tail->next = node; tail = node; }
    }
    void pop() {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }
    T front() { return head->data; }
    bool empty() { return head == nullptr;  }
};
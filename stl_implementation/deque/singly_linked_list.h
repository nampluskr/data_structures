#pragma once 

template<typename T>
struct SinlglyLinkedList {
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
    void push_back(const T& data) {
        Node* node = new Node{ data, nullptr };
        if (head == nullptr) { head = tail = node; }
        else { tail->next = node; tail = node; }
    }
    void push_front(const T& data) {
        // head = new Node{ data, head };
        Node* node = new Node{ data, nullptr };
        if (head == nullptr) { head = tail = node; }
        else { node->next = head; head = node; }
    }
    void pop_front() {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }
    void pop_back() {   // O(N)
        Node* prev = nullptr;
        Node* cur = head;
        while (cur != tail) prev = cur, cur = cur->next;
        if (prev == nullptr) head = tail = nullptr;
        else prev->next = nullptr, tail = prev;
        delete cur;
    }
    T front() { return head->data; }
    T back() { return tail->data; }
    bool empty() { return head == nullptr;  }

};
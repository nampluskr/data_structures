#pragma once 

// data_structures/stl_implementation/deque/singly_linked_list.h

template<typename T>
struct LinearSLLHead {
    struct Node {
        T data;
        Node* next;
    };
    Node* head = nullptr;

    void clear() { 
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push_back(const T& data) {     // O(N)
        Node *node = new Node{ data, nullptr };
        if (head == nullptr) head = node;
        else {
            Node* cur = head;
            while (cur->next != nullptr) cur = cur->next;
            cur->next = node;
        }
    }
    void push_front(const T& data) {    // O(1)
        head = new Node{ data, head };
    }
    void pop_front() {  // O(1)
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void pop_back() {   // O(N)
        Node* prev = nullptr;
        Node* cur = head;
        while (cur->next != nullptr) {
            prev = cur; cur = cur->next;
        }
        if (prev == nullptr) head = cur->next;
        else prev->next = cur->next;
        delete cur;
    }
    T front() { return head->data; }
    T back() {      // O(N)
        Node* cur = head;
        while (cur->next != nullptr) cur = cur->next;
        return cur->data;
    }
    bool empty() { return head == nullptr;  }
};
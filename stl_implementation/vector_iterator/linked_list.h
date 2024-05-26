#pragma once

template<typename T>
struct LinkedList {
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
    T front() { return head->data; }
    T back() { return tail->data; }
    bool empty() { return head == nullptr;  }

    struct Iterator {
        Node* ptr;

        Iterator(Node* ptr) { this->ptr = ptr; }
        bool operator!=(const Iterator& iter) const { return ptr != iter.ptr; }
        bool operator==(const Iterator& iter) const { return ptr == iter.ptr; }
        T& operator*() { return ptr->data; }
        Iterator& operator++() { ptr = ptr->next; return *this; }
        Iterator operator++(int) { Iterator iter = *this; ptr = ptr->next; return iter; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};
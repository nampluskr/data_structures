#pragma once

template<typename T>
struct StackSLL {
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
    void push(const T& data) {
        head = new Node{ data, head };
        // Node* node = new Node{ data, nullptr };
        // if (head == nullptr) { head = node; }
        // else { node->next = head; head = node; }
    }
    void pop() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    T top() { return head->data; }
    bool empty() { return head == nullptr;  }
};
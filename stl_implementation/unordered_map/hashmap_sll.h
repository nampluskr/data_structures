#pragma once

template<typename T>
struct SinlglyLinkedList {
    struct Node {
        T data;
        Node* next = nullptr;
    };
    Node* head = nullptr;

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insert(const T& data) {
        head = new Node{ data, head };
    }
    Node* find(const T& data) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == data) return cur;
            cur = cur->next;
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
        if (prev == nullptr) head = cur->next;
        else prev->next = cur->next;
        delete cur;
    }
};

#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<typename T1, typename T2>
struct HashMapSLL {
    struct Pair {
        T1 first;
        T2 second;
        bool operator==(const Pair& pair) const { return first == pair.first; }
    };
    SinlglyLinkedList<Pair> table[MAX_TABLE];

    void clear() {
        for (int i = 0; i < MAX_TABLE; i++)
            table[i].clear();
    }
    void emplace(const T1& key, const T2& value) {
        int h = hashfunc(key);
        table[h].insert({ key, value });
    }
    void insert(const Pair& pair) {
        emplace(pair.first, pair.second);
    }
    Pair* find(const T1& key) {
        int h = hashfunc(key);
        auto res = table[h].find({ key, {} });
        return &res->data;
    }
    Pair* end() { return nullptr; }
    void erase(const T1& key) {
        int h = hashfunc(key);
        table[h].erase({ key, {} });
    }
    T2& operator[](const T1& key) {
        auto res = find(key);
        if (res == end()) { emplace(key, {}); res = find(key); }
        return res->second;
    }
};
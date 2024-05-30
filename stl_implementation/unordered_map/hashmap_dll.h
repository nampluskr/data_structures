#pragma once

#include <malloc.h>

template<typename T>
struct DoublyLinkedList {
    struct Node
    {
        T data;
        struct Node* prev;
        struct Node* next;
    };
    Node* head = list_create({});

    Node* list_create(const T& data)
    {
        Node* node = (Node*)malloc(sizeof(Node));
        node->prev = NULL;
        node->next = NULL;
        node->data = data;

        return node;
    }

    Node* list_insert(Node* head, Node* new_node)
    {
        Node* next = head->next;

        head->next = new_node;
        new_node->next = next;
        new_node->prev = head;

        if (next != NULL)
        {
            next->prev = new_node;
        }
        return new_node;
    }

    int list_erase(Node* head, const T& data)
    {
        Node* it = head->next;
        int ret = 0;

        while (it != NULL)
        {
            if (it->data == data)
            {
                Node* prev = it->prev;
                Node* next = it->next;
                Node* tmp = it;
                it = it->next;
                prev->next = next;
                if (next != NULL)
                {
                    next->prev = prev;
                }
                free(tmp);
                ret++;
            }
            else
            {
                it = it->next;
            }
        }
        return ret;
    }

    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            free(temp);
        }
        head = list_create({});
    }
    void insert(const T& data) {
        Node* node = list_create(data);
        list_insert(head, node);
    }
    Node* find(const T& data) {
        Node* cur = head->next;
        while (cur != NULL) {
            if (cur->data == data) return cur;
            cur = cur->next;
        }
        return NULL;
    }
    void erase(const T& data) {
        list_erase(head, data);
    }
};

#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<typename T1, typename T2>
struct HashMapDLL {
    struct Pair {
        T1 first;
        T2 second;
        bool operator==(const Pair& pair) const { return first == pair.first; }
    };
    DoublyLinkedList<Pair> table[MAX_TABLE];

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
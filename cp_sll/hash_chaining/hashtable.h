#pragma once

#include "..\singly_linked_list\linkedlist.h"
// using namespace std;

#define MAX_TABLE 1001

template<typename T1, typename T2>
struct HashTable {
    struct Pair {
        T1 key;
        T2 value;
    };
    LinkedList<Pair> table[MAX_TABLE];

    // int hash_func(const T1& key) {
    //     return std::hash<T1>(key);
    // }
    void clear() {
        for (int i = 0; i < MAX_TABLE; i++)
            table[i].clear();
    }
    Pair* find(const T1& key) {
        int hash_value = hash_func(key);
        return table[hash_value].find(key);
    }
    void insert(const T1& key, const T2& value) {
        int hash_value = hash_func(key);
        table[hash_value].push_back({ key, value });
    }
    void erase(const T1& key) {
        int hash_value = hash_func(key);
        table[hash_value].erase(key);
    }
    T2& operator[](const T1& key) {
        int hash_value = hash_func(key);
        auto res = table[hash_value].find(key);
        if (res == nullptr) {
            table[hash_value].push_back({ key, {} });
            return table[hash_value].tail->data.value;
        }
        return res->value;
    }
};
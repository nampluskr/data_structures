#pragma once

#include "linkedlist.h"

#define MAX_TABLE 1001

template<typename T1, typename T2>
struct HashTable {
    struct Pair {
        T1 key;
        T2 value;
    };
    LinkedList<Pair> table[MAX_TABLE];

    int hashfunc(const T1& key) { return hash<T1>(key); }
    void clear() {
        for (int i = 0; i < MAX_TABLE; i++)
            table[i].clear();
    }
    Pair* find(const T1& key) {
        int hashvalue = hashfunc(key);
        return table[hashvalue].find(key);
    }
    void insert(const T1& key, const T2& value) {
        int hashvalue = hashfunc(key);
        table[hashvalue].push_back({ key, value });
    }
    void erase(const T1& key) {
        int hashvalue = hashfunc(key);
        table[hashvalue].erase(key);
    }
    T2& operator[](const T1& key) {
        int hashvalue = hashfunc(key);
        auto res = table[hashvalue].find(key);
        if (res == nullptr) {
            table[hashvalue].push_back({ key, {} });
            return table[hashvalue].tail->data.value;
        }
        return res->value;
    }
};
#pragma once

#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<int max_data>
struct HashMap {
    struct DB { int key, next; } db[max_data];
    struct Pair { int first, second; };
    int table[MAX_TABLE];

    void clear() {
        for (int i = 0; i < MAX_TABLE; i++) table[i] = -1;
        for (int i = 0; i < max_data; i++) { db[i].key = -1, db[i].next = -1; }
    }
    void emplace(int key, int value) {
        int h = hashfunc(key);
        db[value].key = key;
        db[value].next = table[h];
        table[h] = value;
    }
    Pair* find(int key) {
        int h = hashfunc(key);
        int next = table[h];
        while (next != -1 && key != db[next].key) next = db[next].next;
        return (next == -1) ? nullptr : new Pair{ key, next };
    }
    Pair* end() { return nullptr; }
    void erase(int key) {
        auto res = find(key);
        if (res != nullptr) db[res->second].key = -1;
    }
};
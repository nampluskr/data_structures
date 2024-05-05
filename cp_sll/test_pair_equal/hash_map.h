#include "linked_list.h"

#define MAX_TABLE 17

template<typename T1, typename T2>
struct HashMap {
    struct Pair {
        T1 key;
        T2 value;
        bool operator==(const Pair& pair) const { return key == pair.key; }
    };
    LinkedList<Pair> table[MAX_TABLE];

    void insert(const T1& key, const T2& value) {
        int hash_value = key.hash(MAX_TABLE);
        table[hash_value].push_back({ key, value });
    }
    Pair* find(const T1& key) {
        int hash_value = key.hash(MAX_TABLE);
        auto res = table[hash_value].find({ key, {} });
        if (res != nullptr)
            return &res->data;
        return nullptr;
    }
    void erase(const T1& key) {
        int hash_value = key.hash(MAX_TABLE);
        table[hash_value].erase({ key, {} });
    }
    T2& operator[](const T1& key) {
        auto res = find(key);
        if (res == nullptr) {
            insert(key, {});
            return find(key)->value;
            // int hash_value = key.hash(MAX_TABLE);
            // table[hash_value].push_back({ key, {} });
            // return table[hash_value].tail->data.value;
        }
        return res->value;
    }
};
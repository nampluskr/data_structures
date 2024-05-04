#include <iostream>
#include "hashtable.h"
#include "../data.h"

HashTable<int, int> hashmap;

template<typename T>
int hash_func(const T& data) {
    return 0;
}

template<>
int hash_func(const Data& data) {
    return (10000 * data.number + data.id) % 107;
}

void test_hashtable(int option) {
    if (option == 0) return ;

    auto& hm = hashmap;
    hm.clear();
    hm.insert(10, 1);
    hm.insert(20, 2);
    hm.insert(30, 3);
}
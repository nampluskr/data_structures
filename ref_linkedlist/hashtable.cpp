#include <iostream>
#include "hashtable.h"

HashTable<int, int> hashmap;

void test_hashtable(int option) {
    if (option == 0) return ;

    auto& hm = hashmap;
    hm.clear();
    hm.insert(10, 1);
    hm.insert(20, 2);
    hm.insert(30, 3);
}
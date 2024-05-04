#include <iostream>
#include "linkedlist.h"

LinkedList<int> ll0;

template<typename T>
void print_list(T& ll) {
    printf("[size=%d] ", ll.size());
    auto* cur = ll.head;
    while (cur != nullptr){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

template<typename T>
void init_linkedlist(T& ll) {
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);
}

void test_linkedlist(int option){
    if (option == 0) return;
    auto& ll = ll0;

    ll.clear();
    init_linkedlist(ll);
    print_list(ll);

    // while(!ll.empty()) {
    //     auto cur = ll.front();
    //     ll.pop_front();
    //     printf("%d ", cur);
    // }
    // printf("\n");

    // ll.clear();
    // ll.push_front(10);
    // ll.push_front(20);
    // ll.push_front(30);

    // while(!ll.empty()) {
    //     auto cur = ll.front();
    //     ll.pop_front();
    //     printf("%d ", cur);
    // }
    // printf("\n");

    ll.erase(20); print_list(ll);
    ll.erase(30); print_list(ll);
    ll.erase(40); print_list(ll);
}
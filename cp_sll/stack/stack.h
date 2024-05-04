#pragma once 

#include "linkedlist.h"

template<typename T>
struct stack: LinkedList<T> {
    void push(const T& data) { push_front(data); }
    void pop() { pop_back(); }
    T top() { return front(); }
};

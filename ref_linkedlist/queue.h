#pragma once 

#include "linkedlist.h"

template<typename T>
struct queue: LinkedList<T> {
    void push(const T& data) { push_back(data); }
    void pop() { pop_back(); }
};

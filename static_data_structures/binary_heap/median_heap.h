#pragma once

#include "max_heap.h"
#include "min_heap.h"

template<typename T, int max_size>
struct MedianHeap {
    MaxHeap<T, max_size> leftHeap;
    MinHeap<T, max_size> rightHeap;
    int heapSize = 0;

    void clear() {
        leftHeap.clear();
        rightHeap.clear();
        heapSize = 0;
    }
    void push(const T& data) {
        leftHeap.push(data);
        auto temp = leftHeap.top(); leftHeap.pop();
        rightHeap.push(temp);

        if (leftHeap.size() < rightHeap.size()) {
            temp = rightHeap.top(); rightHeap.pop();
            leftHeap.push(temp);
        }
        heapSize++;
    }
    void pop() {
        if (leftHeap.size() == rightHeap.size()) rightHeap.pop();
        else leftHeap.pop();
        heapSize--;
    }
    T median() { 
        if (leftHeap.size() == rightHeap.size()) return rightHeap.top();
        else return leftHeap.top();
    }
    bool empty() { return leftHeap.empty() && rightHeap.empty(); }
    // bool empty() { return heapSize == 0; }
    int size() { return heapSize; }
};
#pragma once

#include "max_heap.h"

// Double-ended Prority Queue
template<typename T, int max_size>
struct MinMaxHeap {
    struct Pair {
        T data; int idx;
        bool operator<(const Pair& other) const { return data < other.data; }
        bool operator>(const Pair& other) const { return data > other.data; }
    };
    MaxHeap<Pair, max_size> maxHeap;
    MinHeap<Pair, max_size> minHeap;
    bool popped[max_size];
    int idx = 0;
    int heapSize = 0;

    void clear() {
        maxHeap.clear();
        minHeap.clear();
        // for (int i = 0; i < max_size; i++) popped[i] = false;
        idx = heapSize = 0;
    }
    template<typename Heap>
    void update(Heap& pq) {
        while (!pq.empty() && popped[pq.top().idx]) pq.pop();
    }
    void push(const T& data) {
        maxHeap.push({ data, idx });
        minHeap.push({ data, idx });
        popped[idx++] = false;
        heapSize++;
    }
    void popTop() {
        update(maxHeap);
        auto top = maxHeap.top(); maxHeap.pop();
        popped[top.idx] = true;
        heapSize--;
    }
    void popBottom() {
        update(minHeap);
        auto bottom = minHeap.top(); minHeap.pop();
        popped[bottom.idx] = true;
        heapSize--;
    }
    T top() {
        update(maxHeap);
        return maxHeap.top().data;
    }
    T bottom() {
        update(minHeap);
        return minHeap.top().data;
    }
    bool empty() { return heapSize <= 0; }
    int size() { return heapSize; }
};
#pragma once

// Prority Queue
template<typename T, int max_size>
struct MinHeap {
    T heap[max_size];
    int heapSize = 0;

    void clear() { heapSize = 0; }
    void push(const T& data) { heap[++heapSize] = data; siftUp(heapSize); }
    void pop() { swap(heap[1], heap[heapSize--]); siftDown(1); }
    T top() { return heap[1]; }
    bool empty() { return heapSize == 0; }
    int size() { return heapSize; }

    void swap(T& a, T& b) { T temp = a; a = b; b = temp; }
    void siftUp(int cur) {
        int parent = cur / 2;
        while (parent >= 1) {
            if (heap[cur] > heap[parent]) break;
            swap(heap[parent], heap[cur]);
            cur = parent, parent = cur / 2;
        }
    }
    void siftDown(int cur) {
        int child = cur * 2;
        while (child <= heapSize) {
            if (child + 1 <= heapSize && heap[child] > heap[child + 1]) child++;
            if (heap[child] > heap[cur]) break;
            swap(heap[cur], heap[child]);
            cur = child, child = cur * 2;
        }
    }
    void heapify(const T arr[], int n) {
        heapSize = 0;
        for (int i = 0; i < n; i++) heap[++heapSize] = arr[i];
        for (int i = n / 2; i >= 1; i--) siftDown(i);
    }
};
#pragma once

/*
min. heap -> max. heap: a < b -> b < a
*/

template<typename T, int max_size>
struct PriorityQueueSWEA {
    T heap[max_size];
    int heapSize = 0;

    void clear(void) { heapSize = 0; }
    void push(const T& data) {
        heap[heapSize] = data;
        int current = heapSize;

        while (current > 0 && heap[(current - 1) / 2] < heap[current]) {
            T temp = heap[(current - 1) / 2];
            heap[(current - 1) / 2] = heap[current];
            heap[current] = temp;
            current = (current - 1) / 2;
        }
        heapSize = heapSize + 1;
    }
    void pop() {
        heapSize = heapSize - 1;
        heap[0] = heap[heapSize];

        int current = 0;
        while (current * 2 + 1 < heapSize) {
            int child;
            if (current * 2 + 2 == heapSize) {
                child = current * 2 + 1;
            } else {
                child = heap[current * 2 + 2] < heap[current * 2 + 1] ? current * 2 + 1 : current * 2 + 2;
            }
            if (heap[child] < heap[current]) {
                break;
            }
            T temp = heap[current];
            heap[current] = heap[child];
            heap[child] = temp;
            current = child;
        }
    }
    bool empty() { return heapSize == 0; }
    T top() { return heap[0]; }
};
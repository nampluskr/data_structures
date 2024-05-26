#pragma once

template<typename T, int max_size>
struct QueueArray {
    T arr[max_size];
    int head = 0;
    int tail = 0;

    void clear() { head = tail = 0; }
    void push(const T& data) { 
        arr[tail++] = data;
        if (tail == max_size) tail = 0;
    }
    void pop() {
        head++;
        if (head == max_size) head = 0;
    }
    T front() { return arr[head]; }
    bool empty(void) { return head == tail; }
};
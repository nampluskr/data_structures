#pragma once

template<typename T, int max_size>
struct ArrayList {
    T arr[max_size];
    int head = 0;
    int tail = 0;

    void clear() { tail = 0; }
    void push_back(const T& data) { arr[tail++] = data; }
    T front() { return arr[head]; }
    T back() { return arr[tail - 1]; }
    bool empty() { return head == tail; }

    // iterators
    T* begin() { return &arr[head]; }
    T* end() { return &arr[tail]; }
};
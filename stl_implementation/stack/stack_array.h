#pragma once

template<typename T, int max_size>
struct StackArray {
    T arr[max_size];
    int tail = 0;

    void clear() { tail = 0; }
    bool empty() { return tail == 0; }
    void push(const T& data) { arr[tail++] = data; }
    void pop() { tail--; }
    T top() { return arr[tail - 1]; }
};
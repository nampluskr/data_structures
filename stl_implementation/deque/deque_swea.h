#pragma once 

// https://www.geeksforgeeks.org/implementation-deque-using-circular-array/

template<typename T, int max_size>
struct DequeSWEA {
    T arr[max_size];
    int head = -1;
    int tail = 0;

    void clear() {
        head = -1;
        tail = 0;
        max_size = max_size;
    }

    bool full() {
        return ((head == 0 && tail == max_size - 1) || head == tail + 1);
    }

    bool empty() {
        return (head == -1);
    }

    void push_front(const T& value) {
        if (head == -1) {
            head = tail = 0;
        }
        else if (head == 0) {
            head = max_size - 1;
        } else {
            head = head - 1;
        }
        arr[head] = value;
    }

    void push_back(const T& value) {
        if (head == -1) {
            head = tail = 0;
        } else if (tail == max_size - 1) {
            tail = 0;
        } else {
            tail = tail + 1;
        }
        arr[tail] = value;
    }

    T front() {
        return arr[head];
    }

    T back() {
        return arr[tail];
    }

    void pop_front() {
        if (head == tail) {
            head = -1;
            tail = -1;
        } else if (head == max_size - 1) {
            head = 0;
        } else {
            head = head + 1;
        }
    }

    void pop_back() {
        if (head == tail) {
            head = -1;
            tail = -1;
        } else if (tail == 0) {
            tail = max_size - 1;
        } else {
            tail = tail - 1;
        }
    }
};
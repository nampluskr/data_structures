### [linked_list.h] Iterator 구현 완료

```cpp
#include <vector>
#include "linked_list.h"
#include "array_list.h"
using namespace std;

struct Data {
    int value, idx;
};

vector<Data> vec;
LinkedList<Data> li;
ArrayList<Data, 20> arr;

template<typename T>
void test_list(T& li) {
    li.clear();
    li.push_back({ 10, 1 });
    li.push_back({ 20, 2 });
    li.push_back({ 30, 3 });
    li.push_back({ 40, 4 });
    li.push_back({ 50, 5 });
    //printf(">> size()  = %d\n", li.size());
    //printf(">> begin() = %d\n", li.begin());
    //printf(">> end()   = %d\n", li.end());

    auto iter1 = li.begin();
    auto iter2 = li.end();


    //printf(">> ");
    //for (auto iter = li.begin(); iter != li.end(); iter++) {
    //    auto data = *iter;
    //    printf("(%d, %d) ", data.value, data.idx);
    //}
    //printf("\n");


    //printf(">> ");
    //for (const auto& data : li)
    //    printf("(%d, %d) ", data.value, data.idx);
    //printf("\n");

    printf(">> front() = (%d, %d)\n", li.front().value, li.front().idx);
    printf(">> back()  = (%d, %d)\n", li.back().value, li.back().idx);
    li.clear();
}

int main()
{
    //printf("\n[vector]\n");
    //test_list(vec);

    //printf("\n[Linked list]\n");
    //test_list(li);

    printf("\n[Array list]\n");
    test_list(arr);

    return 0;
}                                                                       
```

### [array_list.h] iterator 구현 필요

```cpp
#pragma once

template<typename T, int max_size>
struct ArrayList {
    T arr[max_size];
    int head = 0;
    int tail = 0;

    void clear() { tail = 0; }
    void push_back(const T& data) { arr[tail++] = data; }
    bool empty() { return head == tail; }
    T front() { return arr[head]; }
    T back() { return arr[tail - 1]; }
    int size() { return tail - head; }

    struct Iterator {
        T* ptr;

        Iterator(T* ptr = nullptr) { this->ptr = nullptr; }
        bool operator!=(const Iterator& iter) const { return ptr != iter.ptr; }
        T& operator*() { return *ptr; }
        Iterator& operator++() { ptr++; return *this; }
        Iterator operator++(int) { Iterator iter = *this; ptr++; return iter; }
    };
    Iterator begin() { return Iterator(&arr[head]); }
    Iterator end() { return Iterator(&arr[tail]); }
};
```

### [main.cpp] test code

```cpp
#include <vector>
#include "linked_list.h"
#include "array_list.h"
using namespace std;

struct Data {
    int value, idx;
};

vector<Data> vec;
LinkedList<Data> li;
ArrayList<Data, 20> arr;

template<typename T>
void test_list(T& li) {
    li.clear();
    li.push_back({ 10, 1 });
    li.push_back({ 20, 2 });
    li.push_back({ 30, 3 });
    li.push_back({ 40, 4 });
    li.push_back({ 50, 5 });
    //printf(">> size()  = %d\n", li.size());
    //printf(">> begin() = %d\n", li.begin());
    //printf(">> end()   = %d\n", li.end());

    auto iter1 = li.begin();
    auto iter2 = li.end();


    //printf(">> ");
    //for (auto iter = li.begin(); iter != li.end(); iter++) {
    //    auto data = *iter;
    //    printf("(%d, %d) ", data.value, data.idx);
    //}
    //printf("\n");


    //printf(">> ");
    //for (const auto& data : li)
    //    printf("(%d, %d) ", data.value, data.idx);
    //printf("\n");

    printf(">> front() = (%d, %d)\n", li.front().value, li.front().idx);
    printf(">> back()  = (%d, %d)\n", li.back().value, li.back().idx);
    li.clear();
}

int main()
{
    //printf("\n[vector]\n");
    //test_list(vec);

    //printf("\n[Linked list]\n");
    //test_list(li);

    printf("\n[Array list]\n");
    test_list(arr);

    return 0;
}
```

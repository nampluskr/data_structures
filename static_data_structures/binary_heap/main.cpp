#include <cstdio>
#include <queue>
#include "max_heap.h"
#include "min_heap.h"
#include "min_max_heap.h"
#include "median_heap.h"
#include "..\..\data.h"

std::priority_queue<Data> pq_stl;
MaxHeap<Data, 10> max_pq;
MinHeap<Data, 10> min_pq;
MinMaxHeap<Data, 10> depq;
MedianHeap<Data, 10> medpq;

template<typename T>
void test_pq(T& pq) {
    Data d1{ 111, 1 }, d2{ 222, 2}, d3{ 333, 3 }, d4{ 444, 4 }, d5{ 555, 5 };

    pq.push(d3);
    pq.push(d2);
    pq.push(d1);
    pq.push(d5);
    pq.push(d4);

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        printf(">> (%d, %d), size = %d\n", cur.number, cur.id, pq.size());
    }
}

template<typename T>
void test_depq(T& depq) {
    Data d1{ 111, 1 }, d2{ 222, 2}, d3{ 333, 3 }, d4{ 444, 4 }, d5{ 555, 5 };

    depq.clear();
    depq.push(d3);
    depq.push(d2);
    depq.push(d1);
    depq.push(d5);
    depq.push(d4);

    while (!depq.empty()) {
        auto top = depq.top(); depq.popTop();
        printf(">> max = (%d, %d), size = %d\n", top.number, top.id, depq.size());
        if (!depq.empty()) {
            auto bot = depq.bottom(); depq.popBottom();
            printf(">> min = (%d, %d), size = %d\n", bot.number, bot.id, depq.size());
        }
    }
}

template<typename T>
void test_median_pq(T& pq) {
    Data d1{ 111, 1 }, d2{ 222, 2}, d3{ 333, 3 }, d4{ 444, 4 }, d5{ 555, 5 };

    pq.push(d3);
    pq.push(d2);
    pq.push(d1);
    pq.push(d5);
    pq.push(d4);

    while (!pq.empty()) {
        auto cur = pq.median(); pq.pop();
        printf(">> (%d, %d), size = %d\n", cur.number, cur.id, pq.size());
    }
}

int main()
{
    printf("\n[Priority Queue - STL]\n");
    test_pq(pq_stl);

    printf("\n[Priority Queue - Max Heap]\n");
    test_pq(max_pq);

    printf("\n[Priority Queue - Min Heap]\n");
    test_pq(min_pq);

    printf("\n[Double Ended Priority Queue - Min Max Heap]\n");
    test_depq(depq);

    printf("\n[Median Priority Queue - Median Heap]\n");
    test_median_pq(medpq);

    return 0;
}
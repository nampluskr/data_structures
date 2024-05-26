#include <queue>
#include "priority_queue_swea.h"
#include "..\..\data.h"
using namespace std;

priority_queue<Data> pq_stl;
PriorityQueueSWEA<Data, 100> pq_swea;

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
        printf("(%d, %d)\n", cur.number, cur.id);
    }
}

int main()
{
    printf("\n[Priority Queue - STL]\n");
    test_pq(pq_stl);

    printf("\n[Priority Queue - SWEA]\n");
    test_pq(pq_swea);

    return 0;
}
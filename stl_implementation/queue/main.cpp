#include <queue>
#include "..\..\data.h"
#include "queue_array.h"
#include "queue_sll.h"
using namespace std;

queue<Data> q_stl;
QueueArray<Data, 20> q_arr;
QueueSLL<Data> q_sll;

template<typename T>
void test_queue(T& q) {
    Data d1{ 111, 1 }, d2{ 222, 2}, d3{ 333, 3 }, d4{ 444, 4 }, d5{ 555, 5 };

    q.push(d1);
    q.push(d2);
    q.push(d3);
    q.push(d4);
    q.push(d5);

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        printf("(%d, %d)\n", cur.number, cur.id);
    }
    printf("\n");
}

int main()
{
    printf("\n[Queue - STL]\n");
    test_queue(q_stl);

    printf("\n[Queue - Circular Array]\n");
    test_queue(q_arr);

    printf("\n[Queue - Linked List]\n");
    test_queue(q_sll);

    return 0;
}
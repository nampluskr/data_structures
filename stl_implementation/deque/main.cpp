#include <deque>
#include "..\..\data.h"
#include "deque_swea.h"             // circular array
#include "singly_linked_list.h"
#include "doubly_linked_list.h"
using namespace std;

deque<Data> deq;
DequeSWEA<Data, 20> deq_swea;
SinlglyLinkedList<Data> deq_sll;
DoublyLinkedList<Data> deq_dll;

template<typename T>
void test_deque(T& deq) {
    Data d1{ 111, 1 }, d2{ 222, 2}, d3{ 333, 3 }, d4{ 444, 4 }, d5{ 555, 5 };

    deq.push_back(d1);
    deq.push_back(d2);
    deq.push_back(d3);
    deq.push_back(d4);
    deq.push_back(d5);

    printf(">> front() = (%d, %d)\n", deq.front().number, deq.front().id);
    printf(">> back()  = (%d, %d)\n", deq.back().number, deq.back().id);

    printf("\n*** [push_back() / pop_front()] ***\n");
    while (!deq.empty()) {
        auto cur = deq.front(); deq.pop_front();
        printf("(%d, %d) ", cur.number, cur.id);
    }
    printf("\n");

    deq.push_front(d5);
    deq.push_front(d4);
    deq.push_front(d3);
    deq.push_front(d2);
    deq.push_front(d1);

    printf("\n*** [push_front() / pop_back()] ***\n");
    while (!deq.empty()) {
        auto cur = deq.back(); deq.pop_back();
        printf("(%d, %d) ", cur.number, cur.id);
    }
    printf("\n");
}

int main()
{
    printf("\n[STL deque]\n");
    test_deque(deq);

    printf("\n[SWEA deque]\n");
    test_deque(deq_swea);

    printf("\n[Singly Linked List (head/tail)]\n");
    test_deque(deq_sll);

    printf("\n[Doubly Linked List (head/tail)]\n");
    test_deque(deq_sll);

    return 0;
}
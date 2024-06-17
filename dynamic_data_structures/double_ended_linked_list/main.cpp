#include <deque>
#include "..\..\data.h"
#include "linear_sll_head_tail.h"
#include "linear_sll_head.h"
#include "linear_dll_head_tail.h"
#include "circular_dll_head.h"
#include "circular_dll_dummy.h"


std::deque<Data> deq;
LinearSLLHead<Data> sll_head;
LinearSLLHeadTail<Data> sll_head_tail;
LinearDLLHeadTail<Data> dll_head_tail;
CircularDLLHead<Data> circular_dll_head;
CircularDLLDummy<Data> circular_dll_dummy;


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

    printf("\n* push_back() / pop_front()\n");
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

    printf("\n* push_front() / pop_back()\n");
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

    printf("\n[Linear Singly Linked List with Head Node]\n");
    test_deque(sll_head);

    printf("\n[Linear Singly Linked List with Head and Tail Nodes]\n");
    test_deque(sll_head_tail);

    printf("\n[Linear Doubly Linked List with Head and Tail Nodes]\n");
    test_deque(dll_head_tail);

    printf("\n[Circular Doubly Linked List with Head Node]\n");
    test_deque(circular_dll_head);

    printf("\n[Circular Doubly Linked List with Dummy Node]\n");
    test_deque(circular_dll_dummy);

    return 0;
}

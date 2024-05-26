#include <stack>
#include "..\..\data.h"
#include "stack_array.h"
#include "stack_sll.h"
using namespace std;

stack<Data> s_stl;
StackArray<Data, 20> s_arr;
StackSLL<Data> s_sll;

template<typename T>
void test_stack(T& s) {
    Data d1{ 111, 1 }, d2{ 222, 2}, d3{ 333, 3 }, d4{ 444, 4 }, d5{ 555, 5 };

    s.push(d1);
    s.push(d2);
    s.push(d3);
    s.push(d4);
    s.push(d5);

    while (!s.empty()) {
        auto cur = s.top(); s.pop();
        printf("(%d, %d)\n", cur.number, cur.id);
    }
    printf("\n");
}

int main()
{
    printf("\n[Stack - STL]\n");
    test_stack(s_stl);

    printf("\n[Stack - Array]\n");
    test_stack(s_arr);

    printf("\n[Stack - Linked List]\n");
    test_stack(s_sll);

    return 0;
}
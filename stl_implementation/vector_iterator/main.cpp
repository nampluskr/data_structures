#include <cstdio>
#include <vector>
#include "../../data.h"
#include "linked_list.h"
#include "array_list.h"
using namespace std;

vector<Data> vec;
LinkedList<Data> sll;
ArrayList<Data, 20> arr;

template<typename T>
void test_list(T& vec) {
    vec.clear();
    vec.push_back({ 10, 1 });
    vec.push_back({ 20, 2 });
    vec.push_back({ 30, 3 });
    vec.push_back({ 40, 4 });
    vec.push_back({ 50, 5 });

    printf(">> front() = (%d, %d)\n", vec.front().number, vec.front().id);
    printf(">> back()  = (%d, %d)\n", vec.back().number, vec.back().id);

    printf(">> ");
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        auto data = *iter;
        printf("(%d, %d) ", data.number, data.id);
    }
    printf("\n");

    printf(">> ");
    for (const auto& data : vec)
        printf("(%d, %d) ", data.number, data.id);
    printf("\n");

    if (!vec.empty())
        vec.clear();
}

int main()
{
    printf("\n[STL vector]\n");
    test_list(vec);

    printf("\n[Linked list]\n");
    test_list(sll);

    printf("\n[Array list]\n");
    test_list(arr);

    return 0;
}
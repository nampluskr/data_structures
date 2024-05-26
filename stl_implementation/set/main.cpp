#include <set>
#include "..\..\data.h"
#include "set_swea.h"
using namespace std;

set<Data> set_stl;
SetSWEA<Data> set_swea;

template<typename T>
void print_set(const T& s) {
    printf(">> ");
    for (const auto& data: s)
        printf("(%d, %d) ", data.number, data.id);
    printf("\n");
}

void inorder(SetSWEA<Data>::Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    printf("(%d, %d) ", node->key.number, node->key.id);
    inorder(node->right);
}

template<>
void print_set(const SetSWEA<Data>& s) {
    printf(">> ");
    inorder(s.root);
    printf("\n");
}

template<typename T>
void test_set(T& s) {
    Data k1{ 111, 1 }, k2{ 222, 2}, k3{ 333, 3 }, k4{ 444, 4 }, k5{ 555, 5 };

    s.clear();
    s.insert(k3);
    s.insert(k2);
    s.insert(k1);
    s.insert(k5);
    s.insert(k4);
    print_set(s);

    s.erase(k3); print_set(s);
    s.erase(k5); print_set(s);
    s.erase(k2); print_set(s);

    s.clear();      print_set(s);
    s.insert(k4);   print_set(s);
    s.erase(k4);    print_set(s);
}

int main()
{
    printf("\n[Set - STL]\n");
    test_set(set_stl);

    printf("\n[Set - SWEA]\n");
    test_set(set_swea);

    return 0;
}
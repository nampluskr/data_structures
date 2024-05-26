#include <map>
#include "..\..\data.h"
#include "map_swea.h"
using namespace std;

map<Data, int> map_stl;
MapSWEA<Data, int> map_swea;

template<typename T>
void print_map(const T& m) {
    printf(">> ");
    for (const auto& data: m) {
        // auto key = data.first;
        // auto value = data.second;
        // printf("(%d, %d):%d ", key.number, key.id, value);
    }
    printf("\n");
}

void inorder(MapSWEA<Data, 
int>::Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    printf("(%d, %d):%d  ", node->key.number, node->key.id, node->value);
    inorder(node->right);
}

template<>
void print_map(const MapSWEA<Data, int>& m) {
    printf(">> ");
    inorder(m.root);
    printf("\n");
}

template<typename T>
void test_map(T& m) {
    Data d1{ 10, 1 }, d2{ 20, 2 }, d3{ 30, 3 };

    printf("\n*** [Insert] ***\n");
    m.clear();
    m.insert({ d1, 1111 });     // m.emplace(k1, 1111);
    m.insert({ d2, 2222 });     // m.emplace(k2, 2222);

    printf("\n*** [Find] ***\n");
    printf(">> find d1 = %d\n", (m.find(d1) != m.end())? m.find(d1)->second: -1);
    printf(">> find d2 = %d\n", (m.find(d2) != m.end())? m.find(d2)->second: -1);
    printf(">> find d3 = %d\n", (m.find(d3) != m.end())? m.find(d3)->second: -1);

    printf("\n*** [Erase] ***\n");
    m.erase(d1);
    m.erase(d2);
    m.erase(d3);

    printf("\n*** [Find] ***\n");
    printf(">> find d1 = %d\n", (m.find(d1) != m.end())? m.find(d1)->second: -1);
    printf(">> find d2 = %d\n", (m.find(d2) != m.end())? m.find(d2)->second: -1);
    printf(">> find d3 = %d\n", (m.find(d3) != m.end())? m.find(d3)->second: -1);

    printf("\n*** [Assign] ***\n");
    m[d1] = 111;
    m[d2] = 222;

    printf(">> map[d1] = %d\n", m[d1]);
    printf(">> map[d2] = %d\n", m[d2]);
    printf(">> map[d3] = %d\n", m[d3]);

    printf("\n*** [Find] ***\n");
    printf(">> find d1 = %d\n", (m.find(d1) != m.end())? m.find(d1)->second: -1);
    printf(">> find d2 = %d\n", (m.find(d2) != m.end())? m.find(d2)->second: -1);
    printf(">> find d3 = %d\n", (m.find(d3) != m.end())? m.find(d3)->second: -1);

    // printf("\n*** [Erase] ***\n");
    // m.clear();

    // printf("\n*** [Find] ***\n");
    // printf(">> find d1 = %d\n", (int)m.find(d1));
    // printf(">> find d2 = %d\n", (int)m.find(d2));
    // printf(">> find d3 = %d\n", (int)m.find(d3));

    // m.clear();
}


int main()
{
    printf("\n[Map - STL]\n");
    test_map(map_stl);

    return 0;
}
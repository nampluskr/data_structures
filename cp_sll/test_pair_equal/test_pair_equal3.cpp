#if 1
#include <cstdio>
#include "linked_list.h"
#include "hash_map.h"

struct Data {
    int number, id;
    bool operator==(const Data& data) const { return number == data.number && id == data.id; }
    int hash(int max_table) const { return (number * 1000 + id) % max_table; }
};

HashMap<Data, int> map;

int main()
{
    Data d1{10, 1}, d2{20, 2}, d3{30, 3}, d4{40, 4};
    map.insert(d1, 1111);
    map.insert(d2, 2222);
    map.insert(d3, 3333);

    auto res1 = map.find(d1);
    auto res2 = map.find(d2);
    auto res3 = map.find(d3);
    auto res4 = map.find(d4);

    printf("map[{ 10, 1 }] = %d\n", map[d1]);
    printf("map[{ 20, 2 }] = %d\n", map[d2]);
    printf("map[{ 30, 3 }] = %d\n", map[d3]);
    printf("map[{ 40, 4 }] = %d\n", map[d4]);

    map.erase(d1);
    map.erase(d2);
    map.erase(d3);

    printf("map[{ 10, 1 }] = %d\n", map[d1]);
    printf("map[{ 20, 2 }] = %d\n", map[d2]);
    printf("map[{ 30, 3 }] = %d\n", map[d3]);
    printf("map[{ 40, 4 }] = %d\n", map[d4]);

    return 0;
}
#endif
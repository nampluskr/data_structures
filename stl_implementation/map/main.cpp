#include <map>
#include <unordered_map>
#include "map_swea.h"
using namespace std;

#define MAX_DATA    100

struct Data {
    int ID, score, idx;
    bool operator==(const Data& data) const { 
        return ID == data.ID && score == data.score;
    }
} dataDB[MAX_DATA];
int dataCnt;

map<int, int> map_stl;
MapSWEA<int, int> map_swea;


template<typename T>
int new_index(T& m, int key) {
    int idx;
    auto res = m.find(key);
    if (res == m.end()) {
        idx = dataCnt++;
        m.emplace(key, idx);    // m.insert({ key, idx });
    } else
        idx = res->second;
    return idx;
}


template<typename T>
int find_index(T& m, int key) {
    auto res = m.find(key);
    if (res == m.end()) return -1;
    return res->second;
}


template<typename T>
void test_map(T& m) {
    int IDs[] = { 444, 555, 111, 333, 222, 666, };
    int scores[] = { 4000, 5000, 1000, 3000, 2000, 6000, };
    int n = 6;
    dataCnt = 0;

    m.clear();

    printf("*** Insert:\n");
    for (int i = 0; i < n; i++) {
        int idx = new_index(m, IDs[i]);
        dataDB[idx] = { IDs[i], scores[i], idx };
    }

    for (int i = 0; i < n; i++)
        printf(">> (%d, %d)\n", IDs[i], find_index(m, IDs[i]));

    printf("*** erase:\n");
    m.erase(IDs[0]);
    m.erase(IDs[4]);

    for (int i = 0; i < n; i++)
        printf(">> (%d, %d)\n", IDs[i], find_index(m, IDs[i]));

    m.clear();
}


int main()
{
    printf("\n[map - STL]\n");
    test_map(map_stl);

    printf("\n[map - SWEA]\n");
    test_map(map_swea);

    return 0;
}
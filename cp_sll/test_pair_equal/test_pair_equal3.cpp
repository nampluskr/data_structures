#if 1
#include <cstdio>

template<typename T>
struct LinkedList {
    struct Node {
        T data;
        Node* next = nullptr;
    };
    Node* head = nullptr;
    Node* tail = nullptr;

    void push_back(const T& data) {
        Node* node = new Node{ data, nullptr };
        if (head == nullptr ) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    Node* find(const T& data) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == data) return cur;
            cur = cur->next;
        }
        return nullptr;
    }
    void erase(const T& data) {
        Node* prev = nullptr;
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == data) break;
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) return;
        if (prev == nullptr) head = cur->next;
        else prev->next = cur->next;
        if (tail == cur) tail = prev;
        if (head == nullptr) tail = nullptr;
        delete cur;
    }

};

#define MAX_TABLE 17

struct Data {
    int number, id;
    bool operator==(const Data& data) const { return number == data.number && id == data.id; }
};

int hash_func(const Data& data) {
    return (data.number * 1000 + data.id) % MAX_TABLE;
}

template<typename T1, typename T2>
struct HashMap {
    struct Pair {
        T1 key;
        T2 value;
        bool operator==(const Pair& pair) const { return key == pair.key; }
    };
    LinkedList<Pair> table[MAX_TABLE];

    void insert(const T1& key, const T2& value) {
        int hash_value = hash_func(key);
        table[hash_value].push_back({ key, value });
    }
    Pair* find(const T1& key) {
        int hash_value = hash_func(key);
        auto res = table[hash_value].find({ key, {} });
        if (res != nullptr)
            return &res->data;
        return nullptr;
    }
    void erase(const T1& key) {
        int hash_value = hash_func(key);
        table[hash_value].erase({ key, {} });
    }
    T2& operator[](const T1& key) {
        auto res = find(key);
        if (res == nullptr) {
            insert(key, {});
            return find(key)->value;
            // int hash_value = hash_func(key);
            // table[hash_value].push_back({ key, {} });
            // return table[hash_value].tail->data.value;
        }
        return res->value;
    }


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
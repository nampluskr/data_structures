### [hashfunc.cpp]

```cpp
#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<typename T>
int hashfunc(const T& key) { return key % MAX_TABLE; }

int hashfunc(const char* key) {
    unsigned long long h = 5381;
    int c;
    while (c = *key++) h = (((h << 5) + h) + c) % MAX_TABLE;
    return h % MAX_TABLE;
}
```

### [main.cpp]

```cpp
#include <map>
#include <unordered_map>
#include "map_swea.h"
#include "hashfunc.cpp"
#include "hashmap_sll.h"
#include "hashmap_bst.h"
#include "hashmap_dll.h"
#include "hashmap_arr.h"
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
unordered_map<int, int> umap_stl;
HashMapSLL<int, int> hashmap_sll;
HashMapDLL<int, int> hashmap_dll;
HashMapBST<int, int> hashmap_bst;
HashMap<MAX_DATA> hashmap_arr;


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

    printf("\n[unordered_map - STL]\n");
    test_map(umap_stl);

    printf("\n[Hash Map using SLL]\n");
    test_map(hashmap_sll);

    printf("\n[Hash Map using DLL]\n");
    test_map(hashmap_dll);

    printf("\n[Hash Map using BST]\n");
    test_map(hashmap_bst);

    printf("\n[Hash Map using Array]\n");
    test_map(hashmap_arr);

    return 0;
}
```

### [hashmap_sll.h]

```cpp
#pragma once

template<typename T>
struct SinlglyLinkedList {
    struct Node {
        T data;
        Node* next = nullptr;
    };
    Node* head = nullptr;

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insert(const T& data) {
        head = new Node{ data, head };
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
        delete cur;
    }
};

#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<typename T1, typename T2>
struct HashMapSLL {
    struct Pair {
        T1 first;
        T2 second;
        bool operator==(const Pair& pair) const { return first == pair.first; }
    };
    SinlglyLinkedList<Pair> table[MAX_TABLE];

    void clear() {
        for (int i = 0; i < MAX_TABLE; i++)
            table[i].clear();
    }
    void emplace(const T1& key, const T2& value) {
        int h = hashfunc(key);
        table[h].insert({ key, value });
    }
    void insert(const Pair& pair) {
        emplace(pair.first, pair.second);
    }
    Pair* find(const T1& key) {
        int h = hashfunc(key);
        auto res = table[h].find({ key, {} });
        return &res->data;
    }
    Pair* end() { return nullptr; }
    void erase(const T1& key) {
        int h = hashfunc(key);
        table[h].erase({ key, {} });
    }
    T2& operator[](const T1& key) {
        auto res = find(key);
        if (res == end()) { emplace(key, {}); res = find(key); }
        return res->second;
    }
};
```

### [hashmap_dll.h]

```cpp
#pragma once

#include <malloc.h>

template<typename T>
struct DoublyLinkedList {
    struct Node
    {
        T data;
        struct Node* prev;
        struct Node* next;
    };
    Node* head = list_create({});

    Node* list_create(const T& data)
    {
        Node* node = (Node*)malloc(sizeof(Node));
        node->prev = NULL;
        node->next = NULL;
        node->data = data;

        return node;
    }

    Node* list_insert(Node* head, Node* new_node)
    {
        Node* next = head->next;

        head->next = new_node;
        new_node->next = next;
        new_node->prev = head;

        if (next != NULL)
        {
            next->prev = new_node;
        }
        return new_node;
    }

    int list_erase(Node* head, const T& data)
    {
        Node* it = head->next;
        int ret = 0;

        while (it != NULL)
        {
            if (it->data == data)
            {
                Node* prev = it->prev;
                Node* next = it->next;
                Node* tmp = it;
                it = it->next;
                prev->next = next;
                if (next != NULL)
                {
                    next->prev = prev;
                }
                free(tmp);
                ret++;
            }
            else
            {
                it = it->next;
            }
        }
        return ret;
    }

    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            free(temp);
        }
        head = list_create({});
    }
    void insert(const T& data) {
        Node* node = list_create(data);
        list_insert(head, node);
    }
    Node* find(const T& data) {
        Node* cur = head->next;
        while (cur != NULL) {
            if (cur->data == data) return cur;
            cur = cur->next;
        }
        return NULL;
    }
    void erase(const T& data) {
        list_erase(head, data);
    }
};

#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<typename T1, typename T2>
struct HashMapDLL {
    struct Pair {
        T1 first;
        T2 second;
        bool operator==(const Pair& pair) const { return first == pair.first; }
    };
    DoublyLinkedList<Pair> table[MAX_TABLE];

    void clear() {
        for (int i = 0; i < MAX_TABLE; i++)
            table[i].clear();
    }
    void emplace(const T1& key, const T2& value) {
        int h = hashfunc(key);
        table[h].insert({ key, value });
    }
    void insert(const Pair& pair) {
        emplace(pair.first, pair.second);
    }
    Pair* find(const T1& key) {
        int h = hashfunc(key);
        auto res = table[h].find({ key, {} });
        return &res->data;
    }
    Pair* end() { return nullptr; }
    void erase(const T1& key) {
        int h = hashfunc(key);
        table[h].erase({ key, {} });
    }
    T2& operator[](const T1& key) {
        auto res = find(key);
        if (res == end()) { emplace(key, {}); res = find(key); }
        return res->second;
    }
};
```

### [hashmap_bst.h]

```cpp
#pragma once

#include<malloc.h>

template<typename T>
struct BinarySearchTree {
    struct Node {
        T key;
        Node *left, *right;
    };
    Node *root = nullptr;

    Node *newNode(const T& item) {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    Node *insertRec(Node *node, const T& key) {
        if (node == NULL)
            return newNode(key);

        if (key < node->key)
            node->left = insertRec(node->left, key);
        else if (node->key < key)
            node->right = insertRec(node->right, key);

        return node;
    }

    void insert(const T& key) {
        root = insertRec(root, key);
    }

    Node* findRec(Node *node, const T& key) {
        if (node != NULL) {
            if (key == node->key)
                return node;
            if (key < node->key)
                findRec(node->left, key);
            else
                findRec(node->right, key);
        }
        return NULL;
    }

    Node* find(const T& key) {
        return findRec(root, key);
    }

    Node *minValueNode(Node *node) {
        Node *root = node;

        while (root->left != NULL)
            root = root->left;

        return root;
    }

    Node *eraseRec(Node *node, const T& key) {
        if (node == NULL)
            return node;

        if (key < node->key)
            node->left = eraseRec(node->left, key);
        else if (node->key < key )
            node->right = eraseRec(node->right, key);
        else {
            if (node->left == NULL) {
                Node *temp = node->right;
                free(node);
                return temp;
            }
            else if (node->right == NULL) {
                Node *temp = node->left;
                free(node);
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = eraseRec(node->right, temp->key);
        }
        return node;
    }

    void erase(const T& key) {
        root = eraseRec(root, key);
    }

    Node* clearRec(Node* node) {
        if (node == NULL) return nullptr;
        node->left = clearRec(node->left);
        node->right = clearRec(node->right);
        free(node);
        return nullptr;
    }

    void clear() { 
        root = clearRec(root);
    }
};

#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<typename T1, typename T2>
struct HashMapBST {
    struct Pair {
        T1 first;
        T2 second;
        bool operator==(const Pair& pair) const { return first == pair.first; }
        bool operator<(const Pair& pair) const { return first < pair.first; }
    };
    BinarySearchTree<Pair> table[MAX_TABLE];

    void clear() {
        for (int i = 0; i < MAX_TABLE; i++)
            table[i].clear();
    }
    void emplace(const T1& key, const T2& value) {
        int h = hashfunc(key);
        table[h].insert({ key, value });
    }
    void insert(const Pair& pair) {
        emplace(pair.first, pair.second);
    }
    Pair* find(const T1& key) {
        int h = hashfunc(key);
        auto res = table[h].find({ key, {} });
        return &res->key;
    }
    Pair* end() { return nullptr; }
    void erase(const T1& key) {
        int h = hashfunc(key);
        table[h].erase({ key, {} });
    }
    T2& operator[](const T1& key) {
        auto res = find(key);
        if (res == end()) { emplace(key, {}); res = find(key); }
        return res->second;
    }
};
```

### [hashmap_arr.h]

```cpp
#pragma once

#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<int max_data>
struct HashMap {
    struct DB { int key, next; } db[max_data];
    struct Pair { int first, second; };
    int table[MAX_TABLE];

    void clear() {
        for (int i = 0; i < MAX_TABLE; i++) table[i] = -1;
        for (int i = 0; i < max_data; i++) { db[i].key = -1, db[i].next = -1; }
    }
    void emplace(int key, int value) {
        int h = hashfunc(key);
        db[value].key = key;
        db[value].next = table[h];
        table[h] = value;
    }
    Pair* find(int key) {
        int h = hashfunc(key);
        int next = table[h];
        while (next != -1 && key != db[next].key) next = db[next].next;
        return (next == -1) ? nullptr : new Pair{ key, next };
    }
    Pair* end() { return nullptr; }
    void erase(int key) {
        auto res = find(key);
        if (res != nullptr) db[res->second].key = -1;
    }
};
```

### [map_swea.h]

```cpp
#pragma once

template<typename T1, typename T2>
struct MapSWEA {
    struct Node {
        T1 key;
        T2 value;
        Node* left, * right;
    };
    struct Pair { T1 first; T2 second; };
    Node* root;

    Node* insertRec(Node* node, const T1& key, const T2& value) {
        if (node == nullptr) return new Node{ key, value, nullptr, nullptr };

        if (key < node->key)
            node->left = insertRec(node->left, key, value);
        else if (key > node->key)
            node->right = insertRec(node->right, key, value);
        else
            node->value = value;

        return node;
    }

    void emplace(const T1& key, const T2& value) {
        root = insertRec(root, key, value);
    }

    Node* findRec(Node* node, const T1& key) {
        if (node == nullptr) return nullptr;
        if (key == node->key)
            return node;
        if (key < node->key)
            return findRec(node->left, key);
        else if (node->key < key)
            return findRec(node->right, key);
    }

    Pair* find(const T1& key) {
        auto node = findRec(root, key);
        return (node == nullptr) ? nullptr : new Pair{ node->key, node->value };
    }
    Pair* end() { return nullptr; }

    Node* minValueNode(Node* node) {
        Node* root = node;

        while (root->left != nullptr)
            root = root->left;

        return root;
    }

    Node* eraseRec(Node* node, const T1& key) {
        if (node == nullptr)
            return node;

        if (key < node->key)
            node->left = eraseRec(node->left, key);
        else if (key > node->key)
            node->right = eraseRec(node->right, key);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = eraseRec(node->right, temp->key);
        }
        return node;
    }

    void erase(const T1& key) {
        root = eraseRec(root, key);
    }

    void clearRec(Node* node) {
        if (node == nullptr) return;
        clearRec(node->left);
        clearRec(node->right);
        delete node;
    }

    void clear() { clearRec(root); root = nullptr; }

    T2& operator[](const T1& key) {
        auto res = find(key);
        if (res == end()) { emplace(key, {}); res = find(key); }
        return res->second;
    }
};
```

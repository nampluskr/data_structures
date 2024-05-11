#include <malloc.h>

#define NULL (0)

template<typename T>
struct LinkedList {
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
        Node* cur = head->next;
        while (cur != NULL) {
            Node* temp = cur;
            cur = cur->next;
            free(cur);
        }
    }
    void insert(const T& data) { 
        Node* node = list_create(data);
        list_insert(head, node);
    }
    Node* find() {
        Node* cur = head->next;
        whiel (cur != NULL) {
            if (cur->data == data) return cur;
            cur = cur->next;
        }
        return nullptr;
    }
    void erase(const T& data) {
        list_erase(head, data);
    }
};
#include <stdbool.h>
#include <stddef.h>

#ifndef _LINKED_LIST
#define _LINKED_LIST

typedef int Item;

typedef struct _Node {
    Item item;
    struct _Node* prev;
    struct _Node* next;
} Node;

typedef struct {
    size_t len;
    Node* head;
    Node* tail;
} LinkedList;

#endif
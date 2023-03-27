#include "ops.h"

Node* new_node() {
    Node* node = (Node*)malloc(sizeof(Node));

    if (!node)
        return NULL;

    node->next = NULL;
    return node;
}

LinkedList new_list() {
    return {.len = 0, .head = NULL, .tail = NULL};
}

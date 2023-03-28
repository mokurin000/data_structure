#include "ops.h"

// return a empty LinkedList
LinkedList new_list() {
    return (LinkedList){.len = 0, .head = NULL, .tail = NULL};
}

// return NULL on failures
//
// note that it will leave item uninitialized, and set
// 'next' of this node to NULL
Node* new_node() {
    Node* node = (Node*)malloc(sizeof(Node));

    if (!node)
        return NULL;

    node->next = NULL;
    return node;
}

// appends item beside `base`
// return -1 on failures, 0 otherwise.
int push(LinkedList* const list, Node* const base, const Item* const item) {
    Node* node = new_node();

    if (!node)
        return -1;

    node->item = *item;

    list->len++;
    base->next = node;

    return 0;
}

// appends item to the end of list
// return -1 on failures, 0 otherwise.
int push_back(LinkedList* const list, const Item* const item) {
    return push(list, list->tail, item);
}

// appends item to the head of list
// return -1 on failures, 0 otherwise.
int push_head(LinkedList* const list, const Item* const item) {
    return push(list, list->head, item);
}

// remove all elements in list, and call custom resource release
// function if it's not NULL
// return 0 if all items are dropped successfully, or positive integer means
// amount of failures if occured
//
// release should return 0 on success
unsigned clean(LinkedList* const list, int (*release)(Item* const)) {
    Node* head = list->head;
    unsigned count = 0;

    while (head) {
        Node* next = head->next;

        if (!release(&head->item)) {
            count++;
        }
        free(head);
        head = next;
    }

    list->len=0;
    return count;
}

// merge two ascending linkedlist to `dest`
// elements of dest will be unique
void merge_ascending_linkedlist(LinkedList* const dest, const LinkedList src);

// elements of returned list may duplicate
LinkedList ascending_list_insertion(const LinkedList a, const LinkedList b);

// return new linkedlist that have items in `base` but not in `diff`
LinkedList substruct(const LinkedList base, const LinkedList diff);

// split base into two `LinkedList`, former with false ones, latter with true
// ones. drop such values if corresponding list is NULL
void partition(const LinkedList base,
               bool (*condition)(const Item* const, void * const bound),
               LinkedList* const left,
               LinkedList* const right,
               void * const bound);

// return the first node has maximium value in list
Node* max_in(const LinkedList list,
             bool (*compar)(const Item* const, const Item* const));

void reverse_in_place(LinkedList* const list);

// returns immediately if target is NULL.
///
void drain(const LinkedList base,
           LinkedList* const target,
           bool (*condition)(const Item* const));

#include <stdlib.h>

#ifndef _LINKED_LIST_OPTS
#define _LINKED_LIST_OPTS

// core data structures
#include "type.h"

// return a empty LinkedList
LinkedList new_list();

// return NULL on failures
//
// note that it will leave item uninitialized, and set
// 'next' of this node to NULL
Node* new_node();

// appends item beside `base`
// return -1 on failures, 0 otherwise.
int push(LinkedList* const list, Node* const base, const Item* const item);

// appends Node to the end of list
// return -1 on failures, 0 otherwise.
int push_back(LinkedList* const list, const Item* const item);

// appends Node to the head of list
// return -1 on failures, 0 otherwise.
int push_head(LinkedList* const list, const Item* const item);

// remove all elements in list, and call custom resource release
// function if it's not NULL
// return 0 if all items are dropped successfully, or positive integer means
// amount of failures if occured
//
// release should return 0 on success
unsigned clean(LinkedList* const list, int (*release)(Item* const));

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
               bool (*condition)(const Item* const),
               LinkedList* const left,
               LinkedList* const right);

// return the first node has maximium value in list
Node* max_in(const LinkedList list,
             bool (*compar)(const Item* const, const Item* const));

void reverse_in_place(LinkedList* const list);

// returns immediately if target is NULL.
void drain(const LinkedList base,
           LinkedList* const target,
           bool (*condition)(const Item* const));

#endif
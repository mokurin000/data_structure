#ifndef _LINKED_LIST_OPTS
#define _LINKED_LIST_OPTS

// core data structures
#include "type.h"

#include <stdlib.h>

// return a empty LinkedList
LinkedList new_list();

// return NULL on failures
//
// note that it will leave item uninitialized, and set
// 'next' of this node to NULL
Node* new_node();

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

// remove all elements in list, and call custom resource release
// function if it's not NULL
void clean(LinkedList* const list, void (*release)(Item* const));

#endif
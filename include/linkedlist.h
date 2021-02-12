#ifndef LINKEDLIST_H_GUARD
#define LINKEDLIST_H_GUARD

#include <stdint.h>

struct LinkedList;

struct LinkedList *ll_create();
void ll_append(struct LinkedList *ll, void *payload);
void *ll_get(struct LinkedList *ll, uint64_t index);
void ll_destroy(struct LinkedList *ll);

void *ll_pushBack(struct LinkedList *ll, uint64_t);
void *ll_popFront(struct LinkedList *ll, uint64_t);

#endif // LINKEDLIST_H_GUARD

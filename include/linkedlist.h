#ifndef LINKEDLIST_H_GUARD
#define LINKEDLIST_H_GUARD

#include <stdint.h>

struct LinkedList;

struct LinkedList *ll_create();
void ll_append(struct LinkedList *ll, void *payload);
void *ll_get(struct LinkedList *ll, uint64_t index);
void ll_destroy(struct LinkedList *ll);

#endif // LINKEDLIST_H_GUARD

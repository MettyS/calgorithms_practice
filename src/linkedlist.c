#include "linkedlist.h"
#include <stdint.h>
#include <stdlib.h>


struct Node {
    void *payload;
    void *next;
};

struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

struct LinkedList *ll_create() {
    struct LinkedList *const result = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    result->head = NULL;
    return result;
}

void ll_append(struct LinkedList *ll, void *payload) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->payload = payload;
    node->next = NULL;

    if (ll->head == NULL) {
        ll->head = node;
        return;
    } 

    struct Node *ptr = ll->head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = node;
}

void *ll_pushBack(struct LinkedList *ll, uint64_t);
void *ll_popFront(struct LinkedList *ll, uint64_t);

void *ll_get(struct LinkedList *ll, uint64_t index) {
    struct Node *ptr = ll->head;
    for (uint64_t i = 0; i < index; ++i) {
        if (ptr == NULL) {
            return NULL;
        }
        ptr = ptr->next;
    }
    return ptr->payload;
}

void ll_destroy(struct LinkedList *ll) {
    struct Node *ptr = ll->head;
    struct Node *prev = NULL;

    while (ptr != NULL) {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }

    free(ll);
}


#include "linkedlist.h"

#include <stdlib.h>
#include <stdio.h>

#define ASSERT_EQ(l, r) if (l != r) { printf("Failure " #l " != " #r); }

int main() {
    struct LinkedList * const ll = ll_create();
    ll_append(ll, (void *) 123);
    ll_append(ll, (void *) 456);
    ASSERT_EQ(ll_get(ll, 30), NULL);
    ASSERT_EQ(ll_get(ll, 0), (void *) 123);
    ASSERT_EQ(ll_get(ll, 1), (void *) 456);

    ll_destroy(ll);

    return 0;
}

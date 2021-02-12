#include "binaryheap.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


#define ASSERT_EQ(l, r)                  \
    if (l != r)                          \
    {                                    \
        printf("\nFailure " #l " != " #r); \
    }

// typedef bool (*ComparisonFn)(const void *, const void *);
// typedef void * BHPayload;

bool compareInt(const void *l, const void *r) {
    if ((uint64_t)l < (uint64_t)r)
        return true;
    else
        return false;
}

int main() {
    bool (*compare)(const void *, const void *) = &compareInt;
    struct BinaryHeap *bh = bh_create(compare); 

    bh_print(bh);

    bh_push(bh, (void *)5);
    bh_push(bh, (void *)2);
    bh_push(bh, (void *)7);
    bh_push(bh, (void *)10);
    bh_push(bh, (void *)3);
    bh_push(bh, (void *)1);

    bh_print(bh);

    uint64_t pop = (uint64_t)bh_popMin(bh);
    ASSERT_EQ(pop, 1);
    pop = (uint64_t)bh_popMin(bh);
    ASSERT_EQ(pop, 2);
    pop = (uint64_t)bh_popMin(bh);
    ASSERT_EQ(pop, 3);
    //good stuff
    bh_print(bh);

    bh_push(bh, (void *)3);
    bh_push(bh, (void *)1);
    bh_push(bh, (void *)4);
    bh_push(bh, (void *)12);
    bh_push(bh, (void *)11);

    bh_print(bh);

    bh_destroy(bh);

    return 0;
}
#include "binaryheap.h"

#include <stdint.h>
#include <stdlib.h>

// 01 02 03 04 05 06 07 08 09 10
// 03 06 04 10 12 09 08 05 97 98 99

struct BinaryHeap {
  BHPayload *arr;
  ComparisonFn compare;
  uint64_t capacity;
  uint64_t size;
};

struct BinaryHeap *bh_create(ComparisonFn comparison) {
    struct BinaryHeap *bh = (struct BinaryHeap *)malloc(sizeof(struct BinaryHeap));
    BHPayload *arr = (BHPayload *)malloc(256 * sizeof(BHPayload));

    bh->arr = arr;
    bh->compare = comparison;
    bh->capacity = 256;
    bh->size = 0;

    return bh;
}

void bh_destroy(struct BinaryHeap *bh) {
    for (uint64_t i = 0; i < bh->size; ++i) {
        
    }
}
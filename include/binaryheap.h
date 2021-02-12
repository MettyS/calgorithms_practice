#ifndef BINARYHEAP_H_GUARD
#define BINARYHEAP_H_GUARD

#include <stdbool.h>

/// Returns true if lhs < rhs
typedef bool (*ComparisonFn)(const void *, const void *);
typedef void * BHPayload;

struct BinaryHeap;
struct BinaryHeap *bh_create(ComparisonFn comparison);

void bh_push(struct BinaryHeap *bh, BHPayload payload);
BHPayload bh_popMin(struct BinaryHeap *bh);

void bh_destroy(struct BinaryHeap *bh);

#endif // BINARYHEAP_H_GUARD
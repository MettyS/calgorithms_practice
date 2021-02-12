#include "binaryheap.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct BinaryHeap {
  BHPayload *arr;
  ComparisonFn compare;
  uint64_t capacity;
  uint64_t size;
};

struct BinaryHeap *bh_create(ComparisonFn comparison) {
  struct BinaryHeap *bh =
      (struct BinaryHeap *)malloc(sizeof(struct BinaryHeap));
  BHPayload *arr = (BHPayload *)malloc(256 * sizeof(BHPayload));

  bh->arr = arr;
  bh->compare = comparison;
  bh->capacity = 256;
  bh->size = 0;

  return bh;
}

static void bh_swap(BHPayload *arr, uint64_t i, uint64_t j) {
  BHPayload temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

static uint64_t bh_getParentIndex(uint64_t i) {
  uint64_t result = ((i + 1) / 2) - 1;
  if (result < 0 || result == i) {
    return i;
  }
  return result;
}

static uint64_t bh_getChildIndexStart(uint64_t i) {
  uint64_t result = ((i + 1) * 2) - 1;
  return result;
}

void bh_push(struct BinaryHeap *bh, BHPayload payload) {
  ComparisonFn compare = bh->compare;

  if (bh->size == bh->capacity) {
    bh->arr =
        (BHPayload *)realloc(bh->arr, (bh->capacity * 2 * sizeof(BHPayload)));
    if (bh->arr == NULL) {
      exit(1);
    }
    bh->capacity = bh->capacity * 2;
  }
  uint64_t addedItemIndex = bh->size;
  bh->arr[addedItemIndex] = payload;
  uint64_t parentIndex = bh_getParentIndex(addedItemIndex);

  while (compare(bh->arr[addedItemIndex], bh->arr[parentIndex])) {
    bh_swap(bh->arr, addedItemIndex, parentIndex);

    addedItemIndex = parentIndex;
    parentIndex = bh_getParentIndex(addedItemIndex);
  }

  bh->size = bh->size + 1;
}

static uint64_t bh_smallestChildIndex(const struct BinaryHeap *bh, uint64_t i) {
  uint64_t childRowStart = bh_getChildIndexStart(i);
  if (childRowStart >= bh->size) {
    return i;
  }
  uint64_t l = childRowStart;
  if (childRowStart + 1 >= bh->size) {
    return l;
  }
  uint64_t r = childRowStart + 1;

  return bh->compare(bh->arr[l], bh->arr[r]) ? l : r;
}

BHPayload bh_popMin(struct BinaryHeap *bh) {
  if (bh->size == 0) {
    return NULL;
  }
  BHPayload result = bh->arr[0];
  bh->arr[0] = NULL;
  uint64_t parentIndex = 0;
  uint64_t smallestChildIndex = bh_smallestChildIndex(bh, parentIndex);
  while (parentIndex != smallestChildIndex) {
    bh_swap(bh->arr, parentIndex, smallestChildIndex);
    parentIndex = smallestChildIndex;
    smallestChildIndex = bh_smallestChildIndex(bh, parentIndex);
  }
  bh->size = bh->size - 1;
  return result;
}

void bh_print(struct BinaryHeap *bh) {
  printf("\n[ ");
  for (uint64_t i = 0; i < bh->size; ++i) {
    printf("%llu, ", (uint64_t)(bh->arr[i]));
  }
  printf("...[%llu]", (bh->capacity - bh->size));
  printf(" ]\n");
}

void bh_destroy(struct BinaryHeap *bh) {
  free(bh->arr);
  free(bh);
}
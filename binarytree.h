#ifndef BINARYTREE_H_GUARD
#define BINARYTREE_H_GUARD

#include <stdbool.h>
#include <stdint.h>

struct BinaryTree;

struct BinaryTree *bt_create();
void bt_insert(struct BinaryTree *bt, uint64_t payload);
bool bt_contains(struct BinaryTree *bt, uint64_t value);
void bt_destroy(struct BinaryTree *bt);
void bt_preorder(struct BinaryTree *bt);

struct BTIterator;
struct BTIterator *bt_getIterator(struct BinaryTree *bt);
uint64_t bt_nextValue(struct BTIterator *iterator);
void bt_destroyIterator(struct BTIterator *iterator);

#endif
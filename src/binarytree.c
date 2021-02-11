#include "binarytree.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

struct Node {
    uint64_t payload;
    struct Node *left;
    struct Node *right;
};

struct BinaryTree {
    struct Node *root;
};

struct BTIterator {
    struct Node *ptr;
};

struct BinaryTree *bt_create() {
    struct BinaryTree *bt = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    bt->root = NULL;
    return bt;
}

void bt_insert(struct BinaryTree *bt, uint64_t payload) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->payload = payload;
    node->left = NULL;
    node->right = NULL;

    if (bt->root == NULL) {
        bt->root = node;
        return;
    }

    struct Node *ptr = bt->root;
    while (true) {
        if (ptr->payload > payload) {
            if (ptr->left) {
                ptr = ptr->left;
            }
            else {
                ptr->left = node;
                break;
            }
        } 
        else if (ptr->payload < payload) {
            if (ptr->right) {
                ptr = ptr->right;
            }
            else {
                ptr->right = node;
                break;
            }
        }
        else {
            break;
        }
    }
    
}

bool bt_contains(struct BinaryTree *bt, uint64_t value) {
    struct Node *ptr = bt->root;

    while (ptr != NULL) {
        if (ptr->payload == value) {
            return true;
        } 
        else if (ptr->payload > value) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    return false;
}

void bt_destroyNode(struct Node *node) {
    if (node->left != NULL) {
        bt_destroyNode(node->left);
    }

    if (node->right != NULL) {
        bt_destroyNode(node->right);
    }

    free(node);
}

void bt_destroy(struct BinaryTree *bt) {
    if (bt->root != NULL) {
        bt_destroyNode(bt->root);
    }

    free(bt);
}

void bt_nodePreorder(struct Node *node) {
    printf("%llu \n", node->payload);
    if (node->left != NULL) {
        printf("L: ");
        bt_nodePreorder(node->left);
    }
    if (node->right != NULL) {
        printf("R: ");
        bt_nodePreorder(node->right);
    }
}

void bt_preorder(struct BinaryTree *bt) {
    if (bt->root != NULL) {
        bt_nodePreorder(bt->root);
    }
}

struct BTIterator *bt_getIterator(struct BinaryTree *bt);
uint64_t bt_nextValue(struct BTIterator *iterator);
void bt_destroyIterator(struct BTIterator *iterator);


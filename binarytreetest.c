#include "binarytree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ASSERT_EQ(l, r)                  \
    if (l != r)                          \
    {                                    \
        printf("Failure " #l " != " #r); \
    }

int main()
{
    struct BinaryTree *const bt = bt_create();
    bt_insert(bt, 5);
    bt_insert(bt, 4);
    bt_insert(bt, 8);
    bt_insert(bt, 2);
    bt_insert(bt, 3);
    bt_insert(bt, 6);
    bt_insert(bt, 7);
    bt_insert(bt, 10);
    bt_insert(bt, 1);
    bt_insert(bt, 6);
    bt_insert(bt, 6);
    bt_insert(bt, 6);

    ASSERT_EQ(bt_contains(bt, 100), false);
    ASSERT_EQ(bt_contains(bt, 1), true);
    ASSERT_EQ(bt_contains(bt, 0), false);
    ASSERT_EQ(bt_contains(bt, 9), false);
    
    bt_preorder(bt);

    bt_destroy(bt);

    return 0;
}

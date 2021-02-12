#include "adjacencymatrix.h"

#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>

#define ASSERT_EQ(l, r)                  \
    if (l != r)                          \
    {                                    \
        printf("Failure " #l " != " #r); \
    }

int main()
{
    struct AdjacencyMatrix *const am = am_create(5);

    am_printMatrix(am);

    am_createEdge(am, 0, 1, 3);
    am_createEdge(am, 4, 1, 2);
    am_createEdge(am, 1, 2, 6);

    am_printMatrix(am);
    // ASSERT_EQ(bt_contains(bt, 100), false);
    // ASSERT_EQ(bt_contains(bt, 1), true);
    // ASSERT_EQ(bt_contains(bt, 0), false);
    // ASSERT_EQ(bt_contains(bt, 9), false);

    am_destroy(am);

    return 0;
}

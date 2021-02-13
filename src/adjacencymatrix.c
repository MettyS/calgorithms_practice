#include "adjacencymatrix.h"
#include "binaryheap.h"

// for ULLONG_MAX
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Edge {
    uint64_t weight;
    bool visited;
};

struct AdjacencyMatrix {
    struct Edge *matrix;
    uint64_t rowLength;
};

struct AdjacencyMatrix *am_create(uint64_t numNodes) {
    struct AdjacencyMatrix *am = (struct AdjacencyMatrix *)malloc(sizeof(struct AdjacencyMatrix));
    struct Edge *matrix = (struct Edge *)malloc(numNodes * numNodes * sizeof(struct Edge));
    
    for (uint64_t i = 0; i < numNodes*numNodes; ++i) {
        matrix[i].weight = ULLONG_MAX;
        matrix[i].visited = false;
    }

    am->matrix = matrix;
    am->rowLength = numNodes;
    return am;
}

void am_createEdge(struct AdjacencyMatrix *am, uint64_t nodeFrom, uint64_t nodeTo, uint64_t w) {
    uint64_t edgeFromRealIndex = nodeFrom + (am->rowLength * nodeTo);
    // uint64_t nodeToRealIndex = nodeTo + (am->rowLength * nodeFrom);
    am->matrix[edgeFromRealIndex].weight = w;
}

void am_printMatrix(struct AdjacencyMatrix *am) {
    printf(" ");
    for (uint64_t i = 0; i < am->rowLength; ++i) {
        printf("%5llu", i);
    }
    printf("%s%s\n", "    ", "from");
    for (uint64_t i = 0; i < am->rowLength; ++i) {
        printf("%llu", (i));
        for(uint64_t u = 0; u < am->rowLength; ++u) {
            uint64_t realIndex = u + (am->rowLength * i);

            if (am->matrix[realIndex].weight == ULLONG_MAX) {
                printf("%5s", ".");
            }
            else if (am->matrix[realIndex].weight) {
                printf("%5llu", am->matrix[realIndex].weight);
            }
            else {
                printf("%5s", "er");
            }
        }
        printf("\n");
    }
    printf("\n%s\n", "to");
}

void am_destroy(struct AdjacencyMatrix *am) {
    free(am->matrix);
    free(am);
}

struct NodePath {
    uint64_t weight;
    uint64_t node;
};

static bool comparePathWeight(const void *l, const void *r) {
    if (((struct NodePath *)l)->weight < ((struct NodePath *)r)->weight)
        return true;
    else
        return false;
}
// uint64_t ULLONG_MAX is failure
uint64_t am_shortestPath(struct AdjacencyMatrix *am, uint64_t nodeFrom, uint64_t nodeTo) {
    struct BinaryHeap *bh = bh_create(&comparePathWeight);

    struct NodePath *root = (struct NodePath *)malloc(sizeof(struct NodePath));
    root->weight = 0;
    root->node = nodeFrom;

    do {
        uint64_t from = root->node;

        for (uint64_t i = 0; i < am->rowLength; ++i) {
            if (i == nodeFrom) 
                continue;
            if (am->matrix[i].visited) 
                continue;

            uint64_t toIndex = from + (i * am->rowLength);
            // this will set all nodes in this column to visited
            am->matrix[toIndex].visited = true;
            // see if edge is invalid
            if (am->matrix[toIndex].weight == ULLONG_MAX)
                continue;
            // look ahead to see if proposed node has been visited
    
            struct NodePath *node = (struct NodePath *)malloc(sizeof(struct NodePath));
            // add the weight of path to here to the new edge
            node->weight = root->weight + am->matrix[toIndex].weight;
            node->node = i;

            bh_push(bh, node);
        }

        free(root);
        root = bh_popMin(bh);
    } while (root != NULL && root->node != nodeTo);

    uint64_t resWeight = ULLONG_MAX;
    if (root != NULL) {
        resWeight = root->weight;
        free(root);
    }
    bh_destroy(bh);
    
    return resWeight;
}

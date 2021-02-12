#include "adjacencymatrix.h"

// for ULLONG_MAX
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

struct Edge {
    uint64_t weight;
};

struct AdjacencyMatrix {
    struct Edge *matrix;
    uint64_t rowLength;
};

struct AdjacencyMatrix *am_create(uint64_t numNodes) {
    struct AdjacencyMatrix *am = (struct AdjacencyMatrix *)malloc(sizeof(struct AdjacencyMatrix));
    struct Edge *matrix = (struct Edge *)malloc(numNodes * numNodes * sizeof(struct Edge));
    
    am->matrix = matrix;
    am->rowLength = numNodes;
    return am;
}

void am_createEdge(struct AdjacencyMatrix *am, uint64_t nodeFrom, uint64_t nodeTo, uint64_t w) {
    uint64_t nodeFromRealIndex = nodeFrom + (am->rowLength * nodeTo);
    // uint64_t nodeToRealIndex = nodeTo + (am->rowLength * nodeFrom);
    am->matrix[nodeFromRealIndex].weight = w;
}

// uint64_t ULLONG_MAX is failure
uint64_t am_shortestPath(struct AdjacencyMatrix *am, uint64_t nodeFrom, uint64_t nodeTo);

void am_destroy(struct AdjacencyMatrix *am) {
    free(am->matrix);
    free(am);
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

            if (am->matrix[realIndex].weight) {
                printf("%5llu", am->matrix[realIndex].weight);
            }
            else {
                printf("%5s", ".");
            }
        }
        printf("\n");
    }
    printf("\n%s\n", "to");
}
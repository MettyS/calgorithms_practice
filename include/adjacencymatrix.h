#ifndef ADJACENCYMATRIX_H_GUARD
#define ADJACENCYMATRIX_H_GUARD

#include <stdint.h>

struct AdjacencyMatrix;

struct AdjacencyMatrix *am_create(uint64_t numNodes);
void am_createEdge(struct AdjacencyMatrix *am, uint64_t nodeFrom,
                   uint64_t nodeTo, uint64_t weight);

// uint64_t ULLONG_MAX is failure
uint64_t am_shortestPath(struct AdjacencyMatrix *am, uint64_t nodeFrom, uint64_t nodeTo);
void am_destroy(struct AdjacencyMatrix *am);

void am_printMatrix(struct AdjacencyMatrix *am);

#endif
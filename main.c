#include <stdio.h>
#include "graph.h"


int main()
{
    printf("************GRAPH DATA STRUCTURE*************\n");
    int dimension = 0;
    int **adjMatrix = formMatrixFromFile(&dimension);
    if(!adjMatrix)
        printf("MATRIX IS EMPTY OR IT HAS INVALID FORMAT!!!\n(NOTE:Matrix has to be square and initialized only with 0s and 1s.)\n");
    printAdjacencyMatrix(adjMatrix,dimension);
    deleteMatrix(adjMatrix,dimension);
    return 0;
}

//Take graph example from this website:
//https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
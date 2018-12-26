#include "Graph.h"


int main()
{

    printf("************GRAPH DATA STRUCTURE*************\n");
    int dimension = 0;
    int **adjMatrix = formMatrixFromFile(&dimension);
    if(!adjMatrix)
        printf("MATRIX IS EMPTY OR IT HAS INVALID FORMAT!!!\n(NOTE:Matrix has to be square and initialized only with 0s and 1s.)\n");
    else {

        printAdjacencyMatrix(adjMatrix, dimension);


        GRAPH graph;
        int i;

        loadGraph(&graph, adjMatrix, dimension);

        printf("\nAdjacency list:\n");
        for (i = 0; i < graph.numberOfNOdes; i++) {
            printf(" %d:", i + 1);
            printNeighbours(graph.nodes[i]);
            printf("\n");
        }

        printf("BFS: \n");
        BFS(&graph, 0);

        deleteMatrix(adjMatrix, dimension);
    }
    return 0;
}

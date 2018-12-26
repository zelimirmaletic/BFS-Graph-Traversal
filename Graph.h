#include "queueINT.h"
#include "singleChainedListINT.h"
#include <string.h>

#define MAX 10

typedef struct graph
{
	int numberOfNOdes;
    NODE *nodes[MAX];
}GRAPH;

void printNeighbours(NODE *pHead)
{
    printList(pHead);
}

void BFS(GRAPH *graph, int start)
{
    SEGMENT *fron = 0;
    SEGMENT *rear=0;
    int v;
    char visited[MAX] = {0};
    visited[start] = 1;
    addToQueue(&fron,&rear, start);
    while(deleteFromQueue(&fron,&rear,&v))
    {
        printf("Visited: ");
        for (int i = 0; i < MAX; ++i)
            if(visited[i])
                printf("%d ",i);
        printf("\n");
        NODE *current = graph->nodes[v];
        while(current)
        {
            int u = current->info;
            if(!visited[u])
            {
                visited[u]=1;
                addToQueue(&fron,&rear,u);
            }

            current=current->next;
        }
        printf("About to visit: ");
        printQueue(fron);
    }
}

void loadGraph(GRAPH *graph, int **matrix, int dimension)
{
    int i,j, neighbour;
   graph->numberOfNOdes=dimension;
    for(i=0;i<graph->numberOfNOdes;i++)
    {
        graph->nodes[i]=nullptr;
        for(j=0;j<graph->numberOfNOdes;j++)
        {
            if(matrix[i][j] == 49)
                addAtEnd(&(graph->nodes[i]), j);
        }
    }
}


int **allocateMatrix(int matrixDimension)
{
    int **adjMatrix = (int **)calloc(matrixDimension, sizeof(int*));
    for (int i = 0; i <matrixDimension ; ++i)
        adjMatrix[i] = (int *)calloc(matrixDimension, sizeof(int));
    return adjMatrix;
}
int **formMatrixFromFile(int *dimension)
{
    FILE *stream = NULL;
    if(stream=fopen("matrix.txt","r"))
    {
        //Check if txt file is empty
        fseek (stream, 0, SEEK_END);
        if(ftell(stream)==SEEK_SET)
            return NULL;
        rewind(stream);
        //Determinig matrix size(number of columns)
        char *tmp = (char *)calloc(20, sizeof(char));
        fscanf(stream,"%[^\n]", tmp);
        int matrixDimension= *dimension = strlen(tmp);
        free(tmp);
        rewind(stream);
        //count number of rows(lines in txt file)
        int curr,numberOfLines=0;
        do
        {
            curr = fgetc(stream);
            if(curr == '\n')
                numberOfLines++;
        }
        while (curr != EOF);
        //validate square matrix
        if(matrixDimension!=numberOfLines+1)
            return NULL;

        int **adjMatrix = allocateMatrix(matrixDimension);

        rewind(stream);

        //Initializing matrix
        for (int i = 0; i <matrixDimension ; i++)
        {
            for (int j = 0; j < matrixDimension; ++j)
            {
                int c = fgetc(stream);
                if(c == EOF)
                    return NULL;
                else if(c==48 || c== 49)
                    adjMatrix[i][j]=c;
                else
                    return NULL;
            }


            fgetc(stream);//skip new line character
        }
        return adjMatrix;
    }
    else
        printf("\nThere is a problem with reading input file!\n");
    fclose(stream);
}
void printAdjacencyMatrix(int **matrix, int matrixDimension)
{
    if(matrix) {
        printf("\nAdjacency matrix:\n\n");
        for (int i = 0; i < matrixDimension; i++) {
            for (int j = 0; j < matrixDimension; ++j)
                if(matrix[i][j])
                    printf("%c ", matrix[i][j]);
            printf("\n");
        }
    }
}
void deleteMatrix(int **adjMatrix, int matrixDimension)
{
    if(adjMatrix)
    {
        for (int k = 0; k <matrixDimension ; ++k)
            free(adjMatrix[k]);
        free(adjMatrix);
    }
}
















//
// Created by zelimirmaletic on 12/23/18.
//

#ifndef LABORATORIJA4_GRAPH_H
#define LABORATORIJA4_GRAPH_H

#include <string.h>
#include <stdlib.h>
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
        if(ftell(stream)==NULL)
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
        if(matrixDimension!=numberOfLines)
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


#endif //LABORATORIJA4_GRAPH_H

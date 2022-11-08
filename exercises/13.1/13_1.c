#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define DIMENSION 6

int main(void)
{   int **matrix, *p;

    //alocando memória dinamicamente
    matrix = (int **)malloc(DIMENSION * sizeof(int *));

    for (int k = 0; k < DIMENSION; k++)
    {
        // p = *(matrix + k);
        matrix[k] = (int *)malloc(DIMENSION * sizeof(int));
    }

    fillSquareMatrixWithIdentity(matrix, DIMENSION);

    for (int i = 0; i < DIMENSION; i++)
    {
        p = *(matrix + i);
        for (int j = 0; j < DIMENSION; j++)
            printf("%d ", *(p + j));
        printf("\n");
    }
    freeMatrix(matrix, DIMENSION);

    return 0;
}

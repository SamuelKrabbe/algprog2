#include <stdio.h>
#include <stdlib.h>

void fillSquareMatrixWithIdentity(int **matrix, int dimension)
{
    int *p;

    for (int i = 0; i < dimension; i++)
    {
        p = *(matrix + i);

        for (int j = 0; j < dimension; j++)
        {
            *(p + j) = 0;
            *(p + i) = 1;
        }
    }
}

void freeMatrix(int **matrix, int dimension)
{
    for (int i = 0; i < dimension; i++)
        free(*(matrix + i));
    free(matrix);
}
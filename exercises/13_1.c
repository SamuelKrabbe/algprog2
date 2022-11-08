#include <stdio.h>
#include <stdlib.h>
#define DIMENSION 6

void fillSquareMatrixWithIdentity(int **matrix)
{
    int *p;

    for (int i = 0; i < DIMENSION; i++)
    {
        p = *(matrix + i);

        for (int j = 0; j < DIMENSION; j++)
        {
            *(p + j) = 0;
            *(p + i) = 1;
        }
    }
}

void freeMatrix(int **matrix)
{
    for (int i = 0; i < DIMENSION; i++)
        free(*(matrix + i));
    free(matrix);
}

int main(void)
{   int **matrix, *p;

    //alocando memória dinamicamente
    matrix = (int **)malloc(DIMENSION * sizeof(int *));

    for (int k = 0; k < DIMENSION; k++)
    {
        // p = *(matrix + k);
        matrix[k] = (int *)malloc(DIMENSION * sizeof(int));
    }

    fillSquareMatrixWithIdentity(matrix);

    for (int i = 0; i < DIMENSION; i++)
    {
        p = *(matrix + i);
        for (int j = 0; j < DIMENSION; j++)
            printf("%d ", *(p + j));
        printf("\n");
    }
    freeMatrix(matrix);

    return 0;
}

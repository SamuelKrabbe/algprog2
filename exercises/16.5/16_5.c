#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define DIMENSION 3

int main(void)
{
    Matrix *p;
    int *aux, magicSquare;

    //alocando memória dinamicamente
    p = (Matrix *)malloc(sizeof(Matrix));
    p->matrix = (int **)malloc(DIMENSION * sizeof(int *));

    for (int k = 0; k < DIMENSION; k++)
        p->matrix[k] = (int *)malloc(DIMENSION * sizeof(int));

    //lendo a matriz
    for (int i = 0; i < DIMENSION; i++)
    {
        aux = *(p->matrix + i);
        for (int j = 0; j < DIMENSION; j++)
            scanf("%d", aux + j);
    }

    magicSquare = isMagicSquare(p);

    if (magicSquare)
        printf("É um quadrado mágico!\n");
    else
        printf("Não é um quadrado mágico!\n");

    freeMatrix(p);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct matrix
{
    int **matrix;
    int dimension;
}Matrix;

int getMagicNum(Matrix *targetMatrix)
{
    int *p, magicNum, dimension;
    p = *(targetMatrix->matrix);
    magicNum = 0;
    dimension = targetMatrix->dimension;

    for (int i = 0; i < dimension; i++)
        magicNum += *(p + i);
    return magicNum;
}

int checkForRows(Matrix *targetMatrix, int magicNum)
{
    int *p, dimension, rowSum;
    dimension = targetMatrix->dimension;
    rowSum = 0;

    for (int i = 0; i < dimension; i++)
    {
        p = *(targetMatrix->matrix + i);

        for (int j = 0; j < dimension; j++)
            rowSum += *(p + j);

        if (rowSum != magicNum)
            return 0;
    }
    return 1;
}

int checkForColumns(Matrix *targetMatrix, int magicNum)
{
    int *p, dimension, columnSum;
    dimension = targetMatrix->dimension;
    columnSum = 0;

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            p = *(targetMatrix->matrix + j) + i;
            columnSum += *p;
        }

        if (columnSum != magicNum)
            return 0;
    }
    return 1;
}

int checkForDiagonals(Matrix *targetMatrix, int magicNum)
{
    int *p, dimension, mainDiagonalSum, secDiagonalSum;
    dimension = targetMatrix->dimension;
    mainDiagonalSum = 0;
    secDiagonalSum = 0;

    //verificando a diagonal principal
    for (int i = 0; i < dimension; i++)
    {
        p = *(targetMatrix->matrix + i);

        mainDiagonalSum += *(p + i);
    }
    
    if (mainDiagonalSum != magicNum)
            return 0;

    //verificando a diagonal secundária
    for (int i = 0, j = dimension - 1; i < dimension && j >= 0; i++)
    {
        p = *(targetMatrix->matrix + i);

        secDiagonalSum += *(p + j);
    }

    if (secDiagonalSum != magicNum)
            return 0;

    return 1;
}

void freeMatrix(Matrix *targetMatrix)
{
    int *p, dimension;
    dimension = targetMatrix->dimension;

    for (int i = 0; i < dimension; i++)
    {
        p = *(targetMatrix->matrix + i);
        free(p);
    }

    free(targetMatrix->matrix);
}

int isMagicSquare(Matrix *targetMatrix)
{
    int magicNum, rows, columns, diagonals;
    
    magicNum = getMagicNum(targetMatrix);

    //verificando as linhas
    rows = checkForRows(targetMatrix, magicNum);

    //verificando as colunas
    columns = checkForColumns(targetMatrix, magicNum);

    //verificando as diagonais
    diagonals = checkForDiagonals(targetMatrix, magicNum);

    if (rows && columns && diagonals)
        return 1;
    return 0;
}
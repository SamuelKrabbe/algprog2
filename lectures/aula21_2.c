#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, j, row, column, **matriz, **pt;

    scanf("%d %d", &row, &column);

    matriz = (int **)malloc(row * sizeof(int *));

    if (matriz == NULL)
        return 0;

    for (pt = matriz, i = 0; i < row; i++, pt++)
    {
        *pt = (int *)malloc(column * sizeof(int));
        if (*pt == NULL)
            return 0;
    }

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            scanf("%d", &matriz[i][j]);

    pt = matriz;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
            printf("%d ", *(*(pt + i) + j));
        printf("\n");
    }

    for (pt = matriz, i = 0; i < row; i++, pt++)
    {
        free(*pt);
    }

    free(matriz);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(void)
{
    //criando pilha
    Cell *stack, *newCell, *p, *x;
    stack = NULL;

    for (int i = 0; i < 3; i++)
    {
        newCell = createNewCell();
        newCell->content = i;
        stackCell(newCell, &stack);
    }

    //imprimindo conteúdo da pilha
    p = stack;
    for (int j = 0; j < 3; j++)
    {
        printf("%d\n", p->content);
        p = p->nextCell;
    }
    printf("\n");

    //desempilhando o topo
    x = unstackCell(&stack);

    //imprimindo a célula desempilhada
    printf("%d\n", x->content);
    printf("\n");

    //imprimindo conteúdo da pilha desempilhada
    p = stack;
    for (int k = 0; k < 2; k++)
    {
        printf("%d\n", p->content);
        p = p->nextCell;
    }

    return 0;
}

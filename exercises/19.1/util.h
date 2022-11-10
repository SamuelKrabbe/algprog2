#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int content;
    struct cell *nextCell;
}Cell;

Cell *createNewCell()
{
    Cell *p;
    p = (Cell *) malloc(sizeof(Cell));
    p->nextCell = NULL;

    return p;
}

void stackCell(Cell *toStack, Cell **topOfStack)
{
    Cell *aux;
    aux = *topOfStack;
    *topOfStack = toStack;
    toStack->nextCell = aux;
}

Cell *unstackCell(Cell **topOfStack)
{
    Cell *aux;
    aux = *topOfStack;
    *topOfStack = aux->nextCell;
    aux->nextCell = NULL;
    
    return aux;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int content;
    struct cell *nextCell;
    struct cell *lastCell;
} Cell;

Cell *searchValueInList(int x, Cell **lst)
{
    Cell *p;
    p = *lst;

    if (p != NULL && p->content != x)
        p = p->nextCell;

    return p;
}

void insertValueInList(int x, Cell **lst)
{
    Cell *p, *newCell;

    p = *lst;
    newCell = (Cell *)malloc(sizeof(Cell));

    newCell->content = x;
    newCell->nextCell = NULL;
    newCell->lastCell = NULL;

    if (p != NULL)
    {
        while (p->nextCell != NULL)
            p = p->nextCell;
        p->nextCell = newCell;
        newCell->lastCell = p;
    }
    else
        p = newCell;
}

void removeValueFromList(int x, Cell **lst)
{
    Cell *p;

    p = searchValueInList(x, lst);

    if (p != NULL)
    {
        p->lastCell->nextCell = p->nextCell;
        if (p->nextCell != NULL)
            p->nextCell->lastCell = p->lastCell;
        free(p);
    }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int content;
    struct cell *nextCell;
} Cell;

void queueUpWithoutHead(Cell **i, Cell **f, int x)
{
    Cell *newCell;
    newCell = (Cell *)malloc(sizeof(Cell));
    newCell->content = x;
    newCell->nextCell = NULL;

    if (*i == NULL && *f == NULL)
    {
        *i = newCell;
        *f = newCell;
    }
    else
    {
        (*i)->nextCell = newCell;
        *f = newCell;
    }
}

int unqueueWithoutHead(Cell **i, Cell **f)
{
    Cell *p;
    int x = 0;

    if (*i != NULL && *f != NULL)
    {
        if ((*i)->nextCell == NULL)
            *f = NULL;
        x = (*i)->content;
        p = *i;
        *i = (*i)->nextCell;
        free(p);
    }

    return x;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int content;
    struct cell *nextCell;
}Cell;

void appendCell(Cell *toAppend, Cell *appendTo)
{
    appendTo->nextCell = toAppend;
    toAppend->nextCell = NULL;
}

void removeCell(Cell *toRemove)
{
    Cell *aux;
    aux = toRemove;
    aux->nextCell = NULL;
    free(aux);
}

Cell *concatenateWithHead(Cell lst1, Cell lst2)
{
    Cell *p1, *p2, *newLst, *aux;
    p1 = &lst1;
    p2 = &lst2;

    newLst = (Cell *)malloc(sizeof(Cell));
    newLst->nextCell = NULL;

    for (int i = 0; (p1 && p2) != NULL; i++)
    {
        if (p1->content < p2->content)
        {
            appendCell(p1, newLst);
            aux = p1;
            p1 = p1->nextCell;
            removeCell(aux);
            
        }
        else
        {
            if(p2->content < p1->content)
            {
                appendCell(p2, newLst);
                aux = p2;
                p2 = p2->nextCell;
                removeCell(aux);
            }
            else
            {
                appendCell(p1, newLst);
                appendCell(p2, newLst);
                aux = p1;
                p1 = p1->nextCell;
                removeCell(aux);
                aux = p2;
                p2 = p2->nextCell;
                removeCell(aux);
            }
        }
    }
    // appendLst();
    return newLst;
}

Cell *concatenateWithoutHead(Cell *lst1, Cell *lst2)
{

}
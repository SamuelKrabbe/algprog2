#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(void)
{
    Cell *lst1, *lst2, *p, *lst3;

    lst1 = (Cell *) malloc(sizeof(Cell));
    lst1->nextCell = NULL;
    lst2 = (Cell *) malloc(sizeof(Cell));
    lst2->nextCell = NULL;

    p = lst1;

    for (int i = 0; i < 3; i++)
    {
        addNewCellToLst(p);
        p = p->nextCell;
        p->content = i;
    }

    p = lst2; 

    for (int j = 3; j < 6; j++)
    {
        addNewCellToLst(p);
        p = p->nextCell;
        p->content = j;
    }

    //---------------------------------------------

    lst3 = concatenateWithHead(lst1, lst2);
    p = lst3;
    
    for (int k = 0; k < 6; k++)
    {
        p = p->nextCell;
        printf("%d\n", p->content);
    }

    return 0;
}

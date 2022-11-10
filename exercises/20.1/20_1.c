#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
    Cell *i, *f;
    int x = 2, y;

    i = NULL;
    f = NULL;

    queueUpWithoutHead(&i, &f, x);
    y = unqueueWithoutHead(&i, &f);
    printf("%d\n", y);

    if (f != NULL)
        free(f);
}

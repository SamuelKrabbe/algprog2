#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <time.h>
#include "util.h"
#define MAX 1000

//MAIN ===========================================================================================================


int main(void)
{
    int v[MAX];
    float exeTimeMerge, exeTimeQuick;
    struct timeval start, end;

    //Criando o vetor
    for (int i = 0; i < MAX; i++)
    {
        v[i] = rand() % (10 * MAX);
    }

    gettimeofday(&start, NULL);
    mergesort(0, MAX, v);
    gettimeofday(&end, NULL);

    exeTimeMerge = timeDiff(&start, &end);

    //Criando outro vetor
    for (int i = 0; i < MAX; i++)
    {
        v[i] = rand() % (10 * MAX);
    }

    gettimeofday(&start, NULL);
    quicksort(0, (MAX - 1), v);
    gettimeofday(&end, NULL);

    exeTimeQuick = timeDiff(&start, &end);

    printf("mergesort %.8f sec; quicksort %.8f sec\n", exeTimeMerge, exeTimeQuick);

    return 0;
}


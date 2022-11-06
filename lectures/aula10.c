#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <time.h>
#include "util.h"
#define MAX 20

int main(void)
{
    int v[MAX] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21}, x = 2;
    double executionTimeSequencialSearch, executionTimeBinarySearch;
    struct timeval start, end;

    // printf("Insira o numero que procuras (obs.: 0-99): \n");
    // scanf("%d", &x);
    //getRandomVector(v);

    gettimeofday(&start, NULL);
    recursiveSequencialSearch(MAX, v, x);
    gettimeofday(&end, NULL);

    executionTimeSequencialSearch = timeDiff(&start, &end);

    gettimeofday(&start, NULL);
    binarySearch(MAX, v, x);
    gettimeofday(&end, NULL);

    executionTimeBinarySearch = timeDiff(&start, &end);

    printf("O tempo de execucao da busca sequencial recursiva foi de %.8f sec, ja o da busca binaria foi %.8f sec\n", executionTimeSequencialSearch, executionTimeBinarySearch);
    return 0;
}

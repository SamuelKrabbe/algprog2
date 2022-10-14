#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <time.h>
#define MAX 20

int recursiveSequencialSearch(int n, int v[MAX], int x);

int binarySearch(int n, int v[MAX], int x);

float timeDiff(struct timeval *start, struct timeval *end);

int main(void)
{
    int vector[MAX] = {2, 4, 9, 7, 3, 55, 34, 8, 6, 6, 12, 34, 5, 8, 5, 6, 3, 4, 34, 67}, x = 2;
    float executionTimeSequencialSearch, executionTimeBinarySearch;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    recursiveSequencialSearch(MAX, vector, x);
    gettimeofday(&end, NULL);

    executionTimeSequencialSearch = timeDiff(&start, &end);

    gettimeofday(&start, NULL);
    binarySearch(MAX, vector, x);
    gettimeofday(&end, NULL);

    executionTimeBinarySearch = timeDiff(&start, &end);

    printf("O tempo de execução da busca sequencial recursiva foi de %.8f sec, já o da busca binária foi %.8f sec\n", executionTimeSequencialSearch, executionTimeBinarySearch);
    return 0;
}

int recursiveSequencialSearch(int n, int v[MAX], int x)
{
    if (n == 0)
        return -1;
    else
        if (x == v[n - 1])
            return n - 1;
        else
            return recursiveSequencialSearch(n - 1, v, x);
}

int binarySearch(int n, int v[MAX], int x)
{
    int esq, dir, meio;
    esq = -1;
    dir = n;
    while (esq < dir - 1) {
        meio = (esq + dir) / 2;
        if (v[meio] < x)
            esq = meio;
        else
            dir = meio;
    }
    return dir;
}

float timeDiff(struct timeval *start, struct timeval *end)
{
    return((end -> tv_sec - start -> tv_sec) + 1E-6 * (end -> tv_usec - start -> tv_usec));
}

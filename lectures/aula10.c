#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <time.h>
#define MAX 20

int recursiveSequencialSearch(int n, int v[MAX], int x);

int binarySearch(int n, int v[MAX], int x);

float timeDiff(struct timeval *start, struct timeval *end);

void getRandomVector(int *v);

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

// void getRandomVector(int *v)
// {
//     for (int i = 0; i < MAX; i++)
//     {
//         v[i] = rand() % 100;
//     }
// }
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <time.h>
#define MAX 1000

float timeDiff(struct timeval *start, struct timeval *end);

int separa(int p, int r, int v[MAX]);

void quicksort(int p, int r, int v[MAX]);

void intercala(int p, int q, int r, int v[MAX]);

void mergesort(int p, int r, int v[MAX]);

void troca(int *a, int *b);


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


//FUNCTIONS ======================================================================================================


float timeDiff(struct timeval *start, struct timeval *end)
{
    return((end -> tv_sec - start -> tv_sec) + 1E-6 * (end -> tv_usec - start -> tv_usec));
}


int separa(int p, int r, int v[MAX])
{
    int x, i, j;

    x = v[p];
    i = p - 1;
    j = r + 1;

    while (1) {
        do {
            j--;
        } while (v[j] > x);
        do {
            i++;
        } while (v[i] < x);
        if (i < j)
            troca(&v[i], &v[j]);
        else
            return j;
    }
}


/* Recebe um vetor v[p..r-1] e o rearranja em ordem crescente */
void quicksort(int p, int r, int v[MAX])
{
    int q;

    if (p < r) {
        q = separa(p, r, v);
        quicksort(p, q, v);
        quicksort(q+1, r, v);
    }
}


/* Recebe os vetores crescentes v[p..q-1] e v[q..r-1]
e rearranja v[p..r-1] em ordem crescente */
void intercala(int p, int q, int r, int v[MAX])
{
    int i, j, k, w[MAX];
    i = p; j = q; k = 0;

    while (i < q && j < r)
    {
        if (v[i] < v[j])
        {
            w[k] = v[i]; i++;
        }
        else
        {
            w[k] = v[j]; j++;
        }
        k++;
    }

    while (i < q)
    {
    w[k] = v[i]; i++; k++;
    }

    while (j < r)
    {
    w[k] = v[j]; j++; k++;
    }

    for (i = p; i < r; i++)
        v[i] = w[i-p];
}


void mergesort(int p, int r, int v[MAX])
{
    int q;

    if (p < r - 1)
    {
        q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

void troca(int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//aula 10 -------------------------------------------------------------------------------------------------
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
//aula 13 --------------------------------------------------------------------------------------------------
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
//aula 17 --------------------------------------------------------------------------------------------------
int max(int n, int *v)
{
	int i, maior, *p;
	p = v;
	maior = *p;
	for (i = 1; i < n; i++)
		if (*(p + i) > maior)
			maior = p[i];
	return maior;
}
//aula 19 --------------------------------------------------------------------------------------------------
int somaMatriz(int n, const int *A)
{
	int soma, *p;
	soma = 0;

	for (p = *(*A); p < *(*A) + (n * n); p++)
		soma += *p;

	return soma;
}
//aula 21.3 ------------------------------------------------------------------------------------------------
void tabela(double (*f)(double), double a, double b, double incr)
{
    int num_intervalos;
    double x = 0, i;
    // num_intervalos = ceil((b - a) / incr);

    for (i = a; i <= b; i += incr)
    {
        // x = a + i * incr;
        x += i;
        printf("%11.6f %11.6f\n", x, (*f)(x));
    }
}
//aula 23 --------------------------------------------------------------------------------------------------
typedef struct stack
{
    char content;
    struct stack *next;
} Stack;

void stackListWithHead(char x, Stack *top)
{
    Stack *newStack;

    newStack = (Stack *)malloc(sizeof(Stack));

    newStack->content = x;
    newStack->next = top->next;
    top->next = newStack;
}

char unstackListWithHead(Stack *top)
{
    char x;
    Stack *p;

    if (top->next != NULL)
    {
        p = top->next;
        x = p->content;
        top->next = p->next;
        free(p);
        return x;
    }
    else
    {
        printf("Pilha vaia!\n");
        return ' ';
    }
}
//aula 27 ---------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
    
void copyOriginalToNewFile(char *originalFile, char *newFile)
{
    int copiedChar;
    FILE *pOriginal, *pCopy;

    pOriginal = fopen(originalFile, "r");
    if (pOriginal != NULL)
    {
        pCopy = fopen(newFile, "w");
        if (pCopy != NULL)
        {
            copiedChar = fgetc(pOriginal);
            while (copiedChar != EOF)
            {
                fputc(copiedChar, pCopy);
                copiedChar = fgetc(pOriginal);
            }
            fclose(pOriginal);
            fclose(pCopy);
            printf("File copied!\n");
        }
        else
            printf("Couldn't open file %s for writing\n", newFile);
    }
    else
        printf("Couldn't open file %s for reading\n", originalFile);
}

void uppercaseOriginalToNewFile(char *originalFile, char *newFile)
{
    int originalFileChar;
    FILE *pOriginal, *pNew;

    pOriginal = fopen(originalFile, "r");
    if (pOriginal != NULL)
    {
        pNew = fopen(newFile, "w");
        if (pNew != NULL)
        {
            originalFileChar = fgetc(pOriginal);
            while (originalFileChar != EOF)
            {
                if (originalFileChar > 96 && originalFileChar < 123)
                {
                    originalFileChar -= 32;
                    fputc(originalFileChar, pNew);
                }
                else
                    fputc(originalFileChar, pNew);
                originalFileChar = fgetc(pOriginal);
            }
            fclose(pOriginal);
            fclose(pNew);
            printf("Uppercase file created!\n");
        }
        else
            printf("Couldn't open file %s for reading\n", newFile);
    }
    else
        printf("Couldn't open file %s for reading\n", originalFile);
}

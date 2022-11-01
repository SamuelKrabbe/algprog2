#include <stdio.h>
#include <stdlib.h>
#define DIM 50

int somaMatriz(int n, const int *A);

int main()
{
	int A[DIM][DIM], n, soma;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", A[0] + i);
		
	soma = somaMatriz(n, A);

	printf("%d\n", soma);
	return 0;
}

int somaMatriz(int n, const int *A)
{
	int soma, *p;
	soma = 0;

	for (p = *(*A); p < *(*A) + (n * n); p++)
		soma += *p;

	return soma;
}

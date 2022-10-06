#include <stdio.h>
#define MAX 100 

int max(int n, int *v);

int main()
{
	int v[MAX], n, maxValue;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", v + i);
		
	maxValue = max(n, v);

	printf("%d\n", maxValue);
	return 0;
}

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

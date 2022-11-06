#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define MAX 100 

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


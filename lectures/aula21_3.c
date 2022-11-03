#include <stdio.h>
#include <math.h>
#include "util.h"

int main(void)
{
    double inicio, fim, incremento;
    printf("Informe um intervalo [a, b]: ");
    scanf("%lf%lf", &inicio, &fim);
    printf("Informe o incremento: ");
    scanf("%lf", &incremento);
    tabela(cos, inicio, fim, incremento);
    tabela(sin, inicio, fim, incremento);
    tabela(tan, inicio, fim, incremento);
    return 0;
}

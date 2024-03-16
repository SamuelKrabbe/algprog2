#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[50];
    double salarioFixo;
    double vendasNoMes;
    double resultado;
    scanf("%s", nome);

    scanf("%lf", &salarioFixo);

    scanf("%lf", &vendasNoMes);
    resultado = salarioFixo + vendasNoMes * 0.15;
    printf("TOTAL = R$ %.2lf\n", resultado);

    return 0;
}
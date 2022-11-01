#include <stdio.h>
#include <math.h>

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

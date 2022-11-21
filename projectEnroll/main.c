/**************************************************
2 *
3 * Alunos: Samuel Krabbe e Leonardo Perin
4 * Trabalho 1
5 * Professor: Marco Stefanes
6 *
7 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN 4
#define MAX 60

typedef char Codigo[MIN + 1];
typedef char Nome[MAX + 1];

typedef struct disciplina
{
    Codigo codigoDis;
    Nome nomeDis;
    struct disciplina **preReq;
    struct disciplina *proxDis;
}Disciplina;

// FUNÇÕES (referências) --------------------------------------------------------------------------
void insereCodENomeNaLista(Disciplina **lista, char *codigoDis, char *nomeDis);


// MAIN ------------------------------------------------------------------------------------------
int main(void)
{
    Disciplina *lista= NULL;
    Nome nomeCurso, nomeDis;
    Codigo codigoDis;
    int numCursos, numDis;
    
    printf("Quantidade de cursos: ");
    scanf("%d", &numCursos);

    for (int i = 0; i < numCursos; i++)
    {
        printf("Nome do curso: ");
        scanf("%[^\n]s", nomeCurso);
        printf("\n");
        printf("Número de disciplinas: ");
        scanf("%d", &numDis);

        for (int j = 0; j < numDis; j++)
        {
            scanf("Código e nome da disciplina: %s %[^\n]s", codigoDis, nomeDis);
            insereCodENomeNaLista(&lista, codigoDis, nomeDis);
        }
    }

    return 0;
}

// FUNÇÕES ----------------------------------------------------------------------------------------
void insereCodENomeNaLista(Disciplina **lista, char *codigoDis, char *nomeDis)
{
    Disciplina *novaDis, *aux;
    novaDis = (Disciplina*)malloc(sizeof(Disciplina));
    novaDis->proxDis = NULL;
    strcpy(novaDis->codigoDis, codigoDis);
    strcpy(novaDis->nomeDis, nomeDis);

    if (*lista == NULL)
    {
        *lista = novaDis;
    }
    else
    {
        aux = *lista;

        while (aux->proxDis != NULL)
            aux = aux->proxDis;

        aux->proxDis = novaDis;
    }
}

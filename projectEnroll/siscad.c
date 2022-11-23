#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 60
#define MAXPRE 5

typedef char String[MAX];

typedef struct dis
{
    struct dis *proxDisc;
    struct dis *proxPreReq;
    struct dis **listaPreRequisitos;
    String codigo;
    String nome;
} disciplina;

void insere(disciplina **, String, String);
void inserePreRequisito(disciplina **, String, String);
void imprime(disciplina *);

int main()
{
    int numCursos, numDisc, i, j;
    String nomeCurso, nomeDisciplina, codDisciplina, dependente, preRequisito;
    disciplina *lista = NULL;

    scanf("%d", &numCursos);

    for (i = 0; i < numCursos; i++)
    {
        scanf(" %[^\n]s", nomeCurso);
        scanf("%d", &numDisc);

        for (j = 0; j < numDisc; j++)
        {
            scanf("%s %[^\n]s", codDisciplina, nomeDisciplina);
            insere(&lista, codDisciplina, nomeDisciplina);
        }

        scanf("%s %s", preRequisito, dependente);
        while (strcmp(preRequisito, "FIM") != 0)
        {
            inserePreRequisito(&lista, preRequisito, dependente);
            scanf("%s %s", preRequisito, dependente);
        }

        imprime(lista);
    }

    return 0;
}

void insere(disciplina **lista, String codDisc, String nomeDisc)
{
    disciplina *no;
    disciplina *aux;
    aux = *lista;

    no = (disciplina *)malloc(1 * sizeof(disciplina));
    strcpy(no->codigo, codDisc);
    strcpy(no->nome, nomeDisc);
    no->proxDisc = NULL;
    no->proxPreReq = NULL;
    no->listaPreRequisitos = (disciplina **)malloc(1 * sizeof(disciplina *));
    *(no->listaPreRequisitos) = NULL;
    if (*lista == NULL)
    {
        *lista = no;
    }
    else
    {
        while (aux->proxDisc != NULL)
        {
            aux = aux->proxDisc;
        }
        aux->proxDisc = no;
    }
}

// Arrumar os ponteiros que apontam para as proximas materia que sao pre requisitos
void inserePreRequisito(disciplina **lista, String preRequisito, String dependente)
{
    disciplina *aux = *lista;
    disciplina *aux2 = *lista;
    disciplina *aux3;
    while (aux != NULL && strcmp(aux->codigo, dependente) != 0)
    {
        aux = aux->proxDisc;
    }

    while (aux2 != NULL && strcmp(aux2->codigo, preRequisito) != 0)
    {
        aux2 = aux2->proxDisc;
    }

    aux3 = *(aux->listaPreRequisitos);

    if (aux3 == NULL)
    {
        *(aux->listaPreRequisitos) = aux2;
    }
    else
    {
        while (aux3->proxPreReq != NULL)
        {
            aux3 = aux3->proxPreReq;
        }
        aux3->proxPreReq = aux2;
    }
}

void imprime(disciplina *lista)
{
    disciplina *aux;
    while (lista != NULL)
    {
        aux = *(lista->listaPreRequisitos);
        while (aux != NULL)
        {
            if (aux->proxPreReq == NULL)
            {
                printf("[codigo: %s]\n", aux->codigo);
            }
            else
            {
                printf("[codigo: %s]\n", aux->codigo);
            }
            aux = aux->proxPreReq;
        }
        lista = lista->proxDisc;
    }
    printf("\n");
}

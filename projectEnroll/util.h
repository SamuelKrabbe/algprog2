#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN 4
#define MAX 60

// estruturas de dados --------------------------------------------------------------------
typedef char Codigo[MIN + 1];
typedef char Nome[MAX + 1];

typedef struct disciplina
{
    Codigo codigoDis;
    Nome nomeDis;
    struct disciplina **listaPreReq;
    struct disciplina *proxDis;
    struct disciplina *proxPreReq;
} Disciplina;

// FUNÇÕES ---------------------------------------------------------------------
void insereCodigoENomeNaLista(Disciplina **lista, char *codigoDis, char *nomeDis)
{
    Disciplina *novaDis, *aux;

    aux = *lista;
    novaDis = (Disciplina *)malloc(sizeof(Disciplina));
    novaDis->proxDis = NULL;
    novaDis->proxPreReq = NULL;
    novaDis->listaPreReq = (Disciplina **)malloc(1 * sizeof(Disciplina *));
    *(novaDis->listaPreReq) = NULL;

    strcpy(novaDis->codigoDis, codigoDis);
    strcpy(novaDis->nomeDis, nomeDis);

    if (*lista == NULL)
        *lista = novaDis;
    else
    {
        while (aux->proxDis != NULL)
            aux = aux->proxDis;
        aux->proxDis = novaDis;
    }
}

void inserePreReqNaLista(Disciplina **lista, char *preReq, char *disDependente)
{
    Disciplina *celulaPreReq, *celulaDisDep, *aux;
    celulaPreReq = *lista;
    celulaDisDep = *lista;
    aux = *(celulaDisDep->listaPreReq);

    // achando a célula do pré-requisito
    while (strcmp(preReq, celulaPreReq->codigoDis) != 0 && celulaPreReq != NULL)
        celulaPreReq = celulaPreReq->proxDis;

    // achando a célula da disciplina dependente
    while (strcmp(disDependente, celulaDisDep->codigoDis) != 0 && celulaDisDep != NULL)
        celulaDisDep = celulaDisDep->proxDis;

    // inserindo o pré-requisito na lista de pré-requisitos
    if (aux == NULL)
        aux = celulaPreReq;
    else
    {
        while (aux->proxPreReq != NULL)
            aux = aux->proxPreReq;
        aux->proxPreReq = celulaPreReq;
    }
}

void imprimeString(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
        printf("%c", string[i]);
}

void freeCelula(Disciplina **celula)
{
    Disciplina *p, **aux;
    p = *celula;
    aux = p->listaPreReq;
    free(*aux);
    free(aux);
    free(p->proxDis);
    free(p);
}

void imprimeLista(Disciplina **lista, int numDis)
{
    Disciplina *p, *aux;
    // char **vetorParaImprimir;
    int i = 0;

    p = *lista;
    aux = *lista;
    // vetorParaImprimir = (char **)malloc(numDis * sizeof(Codigo));

    // iterando para cada disciplina
    while (p != NULL)
    {
        if (*(p->listaPreReq) == NULL)
        {
            // strcpy(vetorParaImprimir[i], p->codigoDis);
            imprimeString(p->codigoDis);
            p = p->proxDis;
            aux = p;
            i++;
        }
        else
        {
            aux = *(p->listaPreReq);
            while (aux->proxPreReq != NULL)
                aux = aux->proxPreReq;
            // strcpy(vetorParaImprimir[i], aux->codigoDis);
            imprimeString(p->codigoDis);
            freeCelula(&aux);
        }
    }
}

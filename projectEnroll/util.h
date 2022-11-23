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
    Codigo codDisciplina;
    int indexDisciplina;
    int *listaPreRequisitos;
    struct disciplina *proxDisciplina;
} Disciplina;

typedef struct gradeCurricular
{
    Codigo codDisciplina;
    struct gradeCurricular *proxDisciplina;
} Grade;

// célula pacote para não passar valor por valor para uma função
typedef struct pacote
{
    Nome nomeDisciplina;
    int indexDisciplina;
    Codigo codDisciplina;
    Codigo codPreRequisito;
    int numDisciplinas;
} Pacote;

// FUNÇÕES ---------------------------------------------------------------------
void criaEInsereNaLista(Disciplina **lista, Pacote *temp)
{
    Disciplina *novaCelula, *aux;
    int numDisciplinas, indexDisciplina;

    numDisciplinas = temp->numDisciplinas;
    indexDisciplina = temp->indexDisciplina;
    aux = *lista;

    novaCelula = (Disciplina *)malloc(sizeof(Disciplina));
    novaCelula->proxDisciplina = NULL;
    novaCelula->indexDisciplina = indexDisciplina;

    // alocando memória para a lista de indexes
    novaCelula->listaPreRequisitos = (int *)malloc(numDisciplinas * sizeof(int));

    strcpy(novaCelula->codDisciplina, temp->codDisciplina);

    // inserindo nova célula na lista
    if (*lista == NULL)
        *lista = novaCelula;
    else
    {
        while (aux->proxDisciplina != NULL)
            aux = aux->proxDisciplina;
        aux->proxDisciplina = novaCelula;
    }
}

void inserePreReqNaLista(Disciplina **lista, Pacote *temp)
{
    Disciplina *celDependente, *celPreRequisito;
    int *aux;

    celDependente = *lista;
    celPreRequisito = *lista;

    // achando a célula da disciplina dependente e do pré-requisito
    while (strcmp(temp->codDisciplina, celDependente->codDisciplina) != 0 && celDependente != NULL)
        celDependente = celDependente->proxDisciplina;

    while (strcmp(temp->codPreRequisito, celPreRequisito->codDisciplina) != 0 && celPreRequisito != NULL)
        celPreRequisito = celPreRequisito->proxDisciplina;

    // inserindo o pré-requisito na lista de pré-requisitos
    aux = celDependente->listaPreRequisitos;
    if (*aux == 0)
        *aux = celPreRequisito->indexDisciplina;
    else
    {
        while (*aux != 0)
            aux++;
        *aux = celPreRequisito->indexDisciplina;
    }
}

// void criaEInsereNaGrade(Grade **gradeCurricular, char *codDisciplina)
// {
//     Grade *novaCelula, *aux;
//     aux = *gradeCurricular;

//     novaCelula = (Grade *)malloc(sizeof(Grade));
//     novaCelula->proxDisciplina = NULL;

//     strcpy(novaCelula->codDisciplina, codDisciplina);

//     // inserindo nova célula na lista
//     if (aux == NULL)
//         aux = novaCelula;
//     else
//     {
//         while (aux->proxDisciplina != NULL)
//             aux = aux->proxDisciplina;
//         aux->proxDisciplina = novaCelula;
//     }
// }

// int comparaNumDisciplinasListaGrade(Disciplina *lista, Grade *gradeCurricular)
// {
//     int contLista = 0, contGrade = 0;

//     while (lista != NULL)
//     {
//         lista = lista->proxDisciplina;
//         contLista++;
//     }

//     while (gradeCurricular != NULL)
//     {
//         gradeCurricular = gradeCurricular->proxDisciplina;
//         contGrade++;
//     }

//     if (contLista == contGrade)
//         return 1;
//     else
//         return 0;
// }

// int valorEstaNaGrade(char *aux, Grade *gradeCurricular)
// {
//     while (gradeCurricular != NULL)
//     {
//         if (strcmp(aux, gradeCurricular->codDisciplina) == 0)
//             return 1;
//         gradeCurricular = gradeCurricular->proxDisciplina;
//     }
//     return 0;
// }

// Grade *criaGradeCurricular(Disciplina *lista)
// {
//     Disciplina *p;
//     Grade *gradeCurricular = NULL;
//     char **aux;
//     p = lista;

//     // colocando matérias sem pré-requisitos na grade primeiro
//     while (p != NULL)
//     {
//         aux = p->listaPreRequisitos;
//         if (strcmp(*aux, "0000") == 0)
//             criaEInsereNaGrade(&gradeCurricular, p->codDisciplina);
//         p = p->proxDisciplina;
//     }
//     p = lista;

//     // colocando as matérias com pré-requisito
//     while (comparaNumDisciplinasListaGrade(lista, gradeCurricular) == 0)
//     {
//         while (p != NULL)
//         { // retorna 0 se não estiver na grade e 1 se estiver
//             if (valorEstaNaGrade(p->codDisciplina, gradeCurricular) == 0)
//             {
//                 aux = p->listaPreRequisitos;
//                 while (strcmp(*aux, "0000") != 0)
//                 {
//                     if (valorEstaNaGrade(*aux, gradeCurricular))
//                         aux++;
//                     else
//                     {
//                         p = p->proxDisciplina;
//                         aux = p->listaPreRequisitos;
//                     }
//                 }
//                 p = p->proxDisciplina;
//             }
//         }
//         p = lista;
//     }

//     return gradeCurricular;
// }

// void imprimeGradeCurricular(Grade *gradeCurricular)
// {
//     while (gradeCurricular != NULL)
//     {
//         printf("%s ", gradeCurricular->codDisciplina);
//         gradeCurricular = gradeCurricular->proxDisciplina;
//     }
// }

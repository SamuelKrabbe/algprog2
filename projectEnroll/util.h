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
    int *aux, i = 0;
    // int numDisciplinas = temp->numDisciplinas;

    celDependente = *lista;
    celPreRequisito = *lista;

    // achando a célula da disciplina dependente e do pré-requisito
    while (strcmp(temp->codDisciplina, celDependente->codDisciplina) != 0 && celDependente != NULL)
        celDependente = celDependente->proxDisciplina;

    while (strcmp(temp->codPreRequisito, celPreRequisito->codDisciplina) != 0 && celPreRequisito != NULL)
        celPreRequisito = celPreRequisito->proxDisciplina;

    // inserindo o pré-requisito na lista de pré-requisitos
    aux = celDependente->listaPreRequisitos;
    if (aux[i] == 0)
    {
        aux[i] = celPreRequisito->indexDisciplina;
    }
    else
    {
        while (aux[i] != 0)
            i++;
        aux[i] = celPreRequisito->indexDisciplina;
    }
}

void criaCelulaEInsereNaGrade(char *codDisciplina, Grade **gradeCurricular)
{
    Grade *novaCelula, *aux;
    aux = *gradeCurricular;

    novaCelula = (Grade *)malloc(sizeof(Grade));
    novaCelula->proxDisciplina = NULL;

    strcpy(novaCelula->codDisciplina, codDisciplina);

    // inserindo nova célula na lista
    if (*gradeCurricular == NULL)
        *gradeCurricular = novaCelula;
    else
    {
        while (aux->proxDisciplina != NULL)
            aux = aux->proxDisciplina;
        aux->proxDisciplina = novaCelula;
    }
}

int comparaListaComGrade(Disciplina *lista, Grade *gradeCurricular)
{
    int contLista = 0, contGrade = 0;

    while (lista != NULL)
    {
        lista = lista->proxDisciplina;
        contLista++;
    }

    while (gradeCurricular != NULL)
    {
        gradeCurricular = gradeCurricular->proxDisciplina;
        contGrade++;
    }

    if (contLista == contGrade)
        return 1;
    else
        return 0;
}

Disciplina *procuraCelulaNaLista(int indexPreRequisito, Disciplina *lista)
{
    Disciplina *p;
    p = lista;

    while (p != NULL)
    {
        if (p->indexDisciplina == indexPreRequisito)
            return p;
        else
            p = p->proxDisciplina;
    }
    return p;
}

int valorEstaNaGrade(char *valor, Grade *gradeCurricular)
{
    while (gradeCurricular != NULL)
    {
        if (strcmp(valor, gradeCurricular->codDisciplina) == 0)
            return 1;
        else
            gradeCurricular = gradeCurricular->proxDisciplina;
    }
    return 0;
}

Grade *criaGradeCurricular(Disciplina *lista)
{
    Disciplina *p, *aux;
    Grade *gradeCurricular = NULL;
    int *indexPreRequisito, *aux2;
    p = lista;

    // colocando matérias sem pré-requisitos na grade primeiro
    while (p != NULL)
    {
        indexPreRequisito = p->listaPreRequisitos;
        if (*indexPreRequisito == 0)
            criaCelulaEInsereNaGrade(p->codDisciplina, &gradeCurricular);
        p = p->proxDisciplina;
    }

    p = lista;
    // colocando as matérias com pré-requisito
    while (comparaListaComGrade(lista, gradeCurricular) == 0)
    {
        while (p != NULL)
        { // retorna 0 se não estiver na grade e 1 se estiver
            if (valorEstaNaGrade(p->codDisciplina, gradeCurricular))
                p = p->proxDisciplina;
            else
            {
                indexPreRequisito = p->listaPreRequisitos;
                aux2 = indexPreRequisito;
                while (*indexPreRequisito != 0 && *aux2 != 0)
                {
                    aux = procuraCelulaNaLista(*aux2, lista);
                    if (valorEstaNaGrade(aux->codDisciplina, gradeCurricular))
                    {
                        indexPreRequisito++;
                        aux2++;
                    }
                    else
                        aux2 = aux->listaPreRequisitos;
                }
                criaCelulaEInsereNaGrade(aux->codDisciplina, &gradeCurricular);
                // p = p->proxDisciplina;
            }
        }
        p = lista;
    }

    return gradeCurricular;
}

void imprimeGradeCurricular(Grade *gradeCurricular)
{
    while (gradeCurricular != NULL)
    {
        printf("%s ", gradeCurricular->codDisciplina);
        gradeCurricular = gradeCurricular->proxDisciplina;
    }
}

// void freeLista(Disciplina **lista)
// {

// }

// void freeGrade(Grade **grade)
// {
// }

// void freePacote(Pacote **pacote)
// {
// }

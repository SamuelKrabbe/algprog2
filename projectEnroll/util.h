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
void criaCelulaEInsereNaLista(Disciplina **lista, Pacote *pacote)
{
    Disciplina *novaCelula, *aux;
    int numDisciplinas, indexDisciplina;

    numDisciplinas = pacote->numDisciplinas;
    indexDisciplina = pacote->indexDisciplina;
    aux = *lista;

    novaCelula = (Disciplina *)malloc(sizeof(Disciplina));
    novaCelula->proxDisciplina = NULL;
    novaCelula->indexDisciplina = indexDisciplina;

    // alocando memória para a lista de indexes
    novaCelula->listaPreRequisitos = (int *)malloc(numDisciplinas * sizeof(int));

    strcpy(novaCelula->codDisciplina, pacote->codDisciplina);

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

void inserePreReqNaLista(Disciplina **lista, Pacote *pacote)
{
    Disciplina *celDependente, *celPreRequisito;
    int *aux, i = 0;
    // int numDisciplinas = pacote->numDisciplinas;

    celDependente = *lista;
    celPreRequisito = *lista;

    // achando a célula da disciplina dependente e do pré-requisito
    while (strcmp(pacote->codDisciplina, celDependente->codDisciplina) != 0 && celDependente != NULL)
        celDependente = celDependente->proxDisciplina;

    while (strcmp(pacote->codPreRequisito, celPreRequisito->codDisciplina) != 0 && celPreRequisito != NULL)
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

// CRIAÇÃO DA GRADE CURRICULAR
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

Disciplina *procuraCelulaNaLista(int indexPreRequisito, Disciplina **lista)
{
    Disciplina *p;
    p = *lista;

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

//================================================================================================================
Grade *criaGradeCurricular(Disciplina **lista, Grade **gradeCurricular, Disciplina *celula)
{
    Disciplina *p, *aux;
    Grade **grade;
    int *indexPreRequisito;

    p = *lista;
    aux = celula;
    grade = gradeCurricular;
    indexPreRequisito = aux->listaPreRequisitos;

    while (p != NULL)
    {
        if (valorEstaNaGrade(aux->codDisciplina, *grade))
            return *grade;
        else
        {
            while (*indexPreRequisito != 0)
            {
                aux = procuraCelulaNaLista(*indexPreRequisito, lista);
                *grade = criaGradeCurricular(lista, grade, aux);
                indexPreRequisito++;
            }
            criaCelulaEInsereNaGrade(p->codDisciplina, grade);
            p = p->proxDisciplina;
            // return *grade;

            // if (p->proxDisciplina == NULL)
            //     return *grade;
            // else
            //     *grade = criaGradeCurricular(lista, grade, p->proxDisciplina);
        }
    }
    return *grade;
}

Grade *criaGradeCurricular(Disciplina **lista)
{
    Disciplina *p;
    Grade *grade;
    int *indexPreRequisito;

    p = *lista;
    grade = NULL;
    indexPreRequisito = p->listaPreRequisitos;

    while (comparaListaComGrade(*lista, grade) == 0)
    {
        if (p == NULL)
            p = *lista;
        else
        {
            if (valorEstaNaGrade(p->indexDisciplina, grade))
                p = p->proxDisciplina;
            else
            {
                if (*indexPreRequisito != 0)
                {
                    if (valorEstaNaGrade(*indexPreRequisito, grade))
                        indexPreRequisito++;
                    else
                    {
                        p = p->proxDisciplina;
                        indexPreRequisito = p->listaPreRequisitos;
                    }
                }
                else
                {
                    criaCelulaEInsereNaGrade(*indexPreRequisito, &grade);
                    p = p->proxDisciplina;
                }
            }
        }
    }
    return grade;
}
//===============================================================================================================

// IMPRESSÃO E DESALOCAMENTO DE MEMÓRIA
void imprimeGradeCurricular(Grade *gradeCurricular)
{
    while (gradeCurricular != NULL)
    {
        printf("%s ", gradeCurricular->codDisciplina);
        gradeCurricular = gradeCurricular->proxDisciplina;
    }
    printf("\n");
}

void freeLista(Disciplina **lista)
{
    Disciplina **p, *aux;
    int *aux2;
    p = lista;

    while (*lista != NULL)
    {
        aux = *p;
        aux2 = aux->listaPreRequisitos;
        free(aux2);
        *p = aux->proxDisciplina;
        free(aux);
    }
}

void freeGrade(Grade **grade)
{
    Grade **p, *aux;
    p = grade;

    while (*grade != NULL)
    {
        aux = *p;
        *p = aux->proxDisciplina;
        free(aux);
    }
}

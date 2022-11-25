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

int comparaListaComGrade(Disciplina *lista, int *grade, Pacote *pacote)
{
    int numDisciplinas, contLista = 0, contGrade = 0;
    numDisciplinas = pacote->numDisciplinas;

    while (lista != NULL)
    {
        lista = lista->proxDisciplina;
        contLista++;
    }

    for (int i = 0; i < numDisciplinas; i++)
    {
        if (grade[i] != 0)
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

int *criaVetorGrade(Disciplina *lista, Pacote *pacote)
{
    Disciplina *p;
    int *grade, numDisciplinas, *aux;

    p = lista;
    numDisciplinas = pacote->numDisciplinas;
    grade = (int *)malloc(numDisciplinas * sizeof(int));

    for (int i = 0; i < numDisciplinas; i++)
    {
        aux = p->listaPreRequisitos;
        if (*aux == 0)
            grade[i] = p->indexDisciplina;
        p = p->proxDisciplina;
    }
    return grade;
}

int *criaVetorGrade2(Disciplina *lista, Pacote *pacote)
{
    Disciplina *p;
    int *grade2, numDisciplinas, *aux;

    p = lista;
    numDisciplinas = pacote->numDisciplinas;
    grade2 = (int *)malloc(numDisciplinas * sizeof(int));

    for (int i = 0; i < numDisciplinas; i++)
    {
        aux = p->listaPreRequisitos;
        if (*aux != 0)
            grade2[i] = p->indexDisciplina;
        p = p->proxDisciplina;
    }
    return grade2;
}

int valorEstaNoVetor(int aux2, int *grade, Pacote *pacote)
{
    int numDisciplinas;
    numDisciplinas = pacote->numDisciplinas;

    for (int i = 0; i < numDisciplinas; i++)
    {
        if (aux2 == grade[i])
            return 1;
    }
    return 0;
}

int *criaVetorGradeFinal(Disciplina *lista, int *grade, int *grade2, Pacote *pacote)
{
    Disciplina *aux;
    int *grade3, numDisciplinas, *aux2;

    numDisciplinas = pacote->numDisciplinas;
    grade3 = (int *)malloc(numDisciplinas * sizeof(int));

    for (int i = 0; i < numDisciplinas; i++)
    {
        if (grade2[i] != 0)
        {
            aux = procuraCelulaNaLista(grade2[i], lista);
            aux2 = aux->listaPreRequisitos;
            for (int j = 0; *aux2 != 0; j++)
            {
                if (valorEstaNoVetor(*aux2, grade, pacote))
                    aux2++;
                else
                    break;
            }
            if (*aux2 == 0)
                grade3[i] = aux->indexDisciplina;
        }
    }
    return grade3;
}

int *juntaGrades(int *grade1, int *grade2, Pacote *pacote)
{
    int *grade3, numDisciplinas, *aux2;
    numDisciplinas = pacote->numDisciplinas;
    int aux[numDisciplinas];

    grade3 = (int *)malloc((2 * numDisciplinas) * sizeof(int));

    for (int i = 0; i < numDisciplinas; i++)
    {
        if (grade1[i] != 0 && grade2[i] != 0)
        {
            grade3[i] = grade1[i];
            aux[i] = grade2[i];
        }
        else if (grade1[i] != 0 && grade2[i] == 0)
        {
            grade3[i] = grade1[i];
        }
    }

    aux2 = grade3;
    for (int j = 0; j < numDisciplinas; j++)
    {
        while (*aux2 != 0)
            aux2++;
        *aux2 = aux[j];
        aux2++;
    }

    return grade3;
}

// // IMPRESSÃO E DESALOCAMENTO DE MEMÓRIA
void imprimeGradeCurricular(int *grade, Disciplina *lista, Pacote *pacote)
{
    Disciplina *aux;
    int numDisciplinas;
    numDisciplinas = pacote->numDisciplinas;

    for (int i = 0; i < numDisciplinas; i++)
    {
        if (grade[i] != 0)
        {
            aux = procuraCelulaNaLista(grade[i], lista);
            printf("%s ", aux->codDisciplina);
        }
    }
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

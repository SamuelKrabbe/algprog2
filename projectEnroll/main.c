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
#include "util.h"
#define MIN 4
#define MAX 60
#define CONST 1

int main(void)
{
    Disciplina *lista = NULL, *p;
    // Grade *gradeCurricular = NULL;
    Pacote *temp;
    Nome nomeCurso;
    Codigo preRequisito, disciplinaDependente;
    int numCursos, numDisciplinas, stopFlag1, stopFlag2, *aux;

    temp = (Pacote *)malloc(sizeof(Pacote));

    scanf("%d", &numCursos);
    printf("\n");

    // iterando para cada curso
    for (int i = 0; i < numCursos; i++)
    {
        scanf(" %[^\n]s", nomeCurso);
        scanf("%d", &numDisciplinas);
        temp->numDisciplinas = numDisciplinas;

        // lendo as disciplinas do curso
        for (int j = 0; j < numDisciplinas; j++)
        {
            scanf("%s %[^\n]s", temp->codDisciplina, temp->nomeDisciplina);
            temp->indexDisciplina = j + 1;
            criaEInsereNaLista(&lista, temp);
        }

        // teste1
        p = lista;
        while (p != NULL)
        {
            printf("%s\n", p->codDisciplina);
            p = p->proxDisciplina;
        }

        // setando a lista de pré-requisitos para 0;
        p = lista;
        while (p != NULL)
        {
            aux = p->listaPreRequisitos;
            for (int k = 0; k < numDisciplinas; k++)
                aux[k] = 0;
            p = p->proxDisciplina;
        }

        // lendo os pré-requisitos de cada disciplina
        while (CONST)
        {
            scanf("%s %s", preRequisito, disciplinaDependente);

            // para o laço se as entradas derem 'FIM FIM'
            stopFlag1 = strcmp(preRequisito, "FIM");
            stopFlag2 = strcmp(disciplinaDependente, "FIM");
            if (stopFlag1 == 0 && stopFlag2 == 0)
                break;

            strcpy(temp->codPreRequisito, preRequisito);
            strcpy(temp->codDisciplina, disciplinaDependente);

            inserePreReqNaLista(&lista, temp);
        }
        printf("\n");
        printf("ATÉ AQUI FUNCIONOU!!!\n");

        // teste2
        p = lista;
        while (p != NULL)
        {
            aux = p->listaPreRequisitos;
            for (int n = 0; n < numDisciplinas; n++)
                printf("%d\n", aux[n]);
            p = p->proxDisciplina;
        }

        // gradeCurricular = criaGradeCurricular(lista);
        // imprimeGradeCurricular(gradeCurricular);
    }

    return 0;
}
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
    Disciplina *lista = NULL, *aux;
    // Grade *gradeCurricular = NULL;
    Pacote *pacote;
    Nome nomeCurso;
    Codigo preRequisito, disciplinaDependente;
    int numCursos, numDisciplinas, stopFlag1, stopFlag2, *grade;
    //, *aux, *p

    pacote = (Pacote *)malloc(sizeof(Pacote));

    scanf("%d", &numCursos);
    printf("\n");

    // iterando para cada curso
    for (int i = 0; i < numCursos; i++)
    {
        scanf(" %[^\n]s", nomeCurso);
        scanf("%d", &numDisciplinas);
        pacote->numDisciplinas = numDisciplinas;

        // lendo as disciplinas do curso
        for (int j = 0; j < numDisciplinas; j++)
        {
            scanf("%s %[^\n]s", pacote->codDisciplina, pacote->nomeDisciplina);
            pacote->indexDisciplina = j + 1;
            criaCelulaEInsereNaLista(&lista, pacote);
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

            strcpy(pacote->codPreRequisito, preRequisito);
            strcpy(pacote->codDisciplina, disciplinaDependente);

            inserePreReqNaLista(&lista, pacote);
        }
        printf("\n");

        grade = criaVetorGrade(lista, pacote);

        // gradeCurricular = criaGradeCurricular(&lista, &gradeCurricular, lista);
        printf("ATÉ AQUI FUNCIONOU!!!\n");

        for (int k = 0; k < numDisciplinas; k++)
        {
            if (grade[k] != 0)
            {
                aux = procuraCelulaNaLista(grade[k], &lista);
                printf("%s ", aux->codDisciplina);
            }
        }
        printf("\n");

        verifica(lista, grade, pacote);
        // imprimeGradeCurricular(gradeCurricular);

        freeLista(&lista);
        // freeGrade(&gradeCurricular);
    }

    return 0;
}
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
    Disciplina *lista = NULL;
    Pacote *pacote;
    Nome nomeCurso;
    Codigo preRequisito, disciplinaDependente;
    int numCursos, numDisciplinas, stopFlag1, stopFlag2, *grade, *grade2, *grade3, *aux;

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
        imprimeGradeCurricular(grade, lista, pacote);

        grade2 = criaVetorGrade2(lista, pacote);

        printf("\n");

        grade3 = criaVetorGradeFinal(lista, grade, grade2, pacote);
        imprimeGradeCurricular(grade3, lista, pacote);
        printf("\n");

        while (1)
        {
            aux = juntaGrades(grade, grade3, pacote);
            imprimeGradeCurricular(aux, lista, pacote);
            if (comparaListaComGrade(lista, aux, pacote) != 0)
            {
                grade = criaVetorGradeFinal(lista, aux, grade2, pacote);
                grade3 = juntaGrades(grade, aux, pacote);
            }
            else
                break;
        }
        // imprimeGradeCurricular(aux, lista, pacote);

        printf("\n");
        freeLista(&lista);
    }

    return 0;
}
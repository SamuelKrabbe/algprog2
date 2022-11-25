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
    Grade *gradeParaImpressao = NULL, *aux2;
    Pacote *pacote;
    Nome nomeCurso;
    Codigo preRequisito, disciplinaDependente;
    int numCursos, numDisciplinas, stopFlag1, stopFlag2, *semPreReq, *dependencias, *grade, *aux3;

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

        dependencias = criaVetorGrade2(lista, pacote);
        
        semPreReq = criaVetorGrade(lista, pacote);
        for (int k = 0; k < numDisciplinas; k++)
        {
            if (semPreReq[k] != 0)
            {
                aux = procuraCelulaNaLista(semPreReq[k], lista);
                criaGradeEncadeada(&gradeParaImpressao, aux);
            }
        }


        printf("\n");

        grade = criaVetorGradeFinal(lista, semPreReq, dependencias, pacote);

        for (int m = 0; m < numDisciplinas; m++)
        {
            if (grade[m] != 0)
            {
                aux = procuraCelulaNaLista(grade[m], lista);
                criaGradeEncadeada(&gradeParaImpressao, aux);
            }
        }

        aux2 = gradeParaImpressao;
        aux3 = (int *)malloc(numDisciplinas * sizeof(int));

        for (int k = 0; k < numDisciplinas && aux2 != NULL; k++)
        {
            aux3[k] = aux2->indexDisciplina;
            aux2 = aux2->proxDisciplina;
        }

        grade = criaVetorGradeFinal(lista, aux3, dependencias, pacote);

        for (int n = 0; n < numDisciplinas; n++)
        {
            if (grade[n] != 0)
            {
                aux = procuraCelulaNaLista(grade[n], lista);
                criaGradeEncadeada(&gradeParaImpressao, aux);
            }
        }

        aux2 = gradeParaImpressao;
        for (int q = 0; q < numDisciplinas && aux2 != NULL; q++)
        {
            aux3[q] = aux2->indexDisciplina;
            aux2 = aux2->proxDisciplina;
        }

        grade = criaVetorGradeFinal(lista, aux3, dependencias, pacote);
        for (int r = 0; r < numDisciplinas; r++)
        {
            if (grade[r] != 0)
            {
                aux = procuraCelulaNaLista(grade[r], lista);
                criaGradeEncadeada(&gradeParaImpressao, aux);
            }
        }

        aux2 = gradeParaImpressao;
        for (int s = 0; s < numDisciplinas && aux2 != NULL; s++)
        {
            aux3[s] = aux2->indexDisciplina;
            aux2 = aux2->proxDisciplina;
        }

        for (int t = 0; t < numDisciplinas; t++)
        {
            if (dependencias[t] != 0)
            {
                for (int v = 0; v < numDisciplinas; v++)
                {
                    if (dependencias[t] == aux3[v])
                        break;
                }
            }
        }
        // while (comparaListaComGrade(lista, gradeParaImpressao) != 1)
        // {
        //     grade = criaVetorGradeFinal(lista, aux3, dependencias, pacote);
        //     for (int n = 0; n < numDisciplinas; n++)
        //     {
        //         if (grade[n] != 0)
        //         {
        //             aux = procuraCelulaNaLista(grade[n], lista);
        //             criaGradeEncadeada(&gradeParaImpressao, aux);
        //         }
        //     }
        //     aux2 = gradeParaImpressao;
        //     for (int k = 0; k < numDisciplinas && aux2 != NULL; k++)
        //     {
        //         if (aux3[k] == 0)
        //         {
        //             aux3[k] = aux2->indexDisciplina;
        //             aux2 = aux2->proxDisciplina;
        //         }
        //     }
        //     aux3 = grade;
        // }
        imprimeGradeCurricular(gradeParaImpressao, lista);

        printf("\n");
        freeLista(&lista);
        // gradeParaImpressao = NULL;
    }

    return 0;
}
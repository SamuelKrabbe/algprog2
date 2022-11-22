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

int main(void)
{
    Disciplina *lista = NULL;
    Nome nomeCurso, nomeDis;
    Codigo codigoDis, preReq, disciplinaDep;
    int numCursos, numDis;

    scanf("%d", &numCursos);
    printf("\n");

    // iterando para cada curso
    for (int i = 0; i < numCursos; i++)
    {
        scanf("%[^\n]s", nomeCurso);
        scanf("%d", &numDis);

        // lendo as disciplinas do curso
        for (int j = 0; j < numDis; j++)
        {
            scanf("%s %[^\n]s", codigoDis, nomeDis);
            insereCodigoENomeNaLista(&lista, codigoDis, nomeDis);
        }

        // lendo os pré-requisitos de cada disciplina
        scanf("%s %s", preReq, disciplinaDep);
        while (strcmp(preReq, "FIM") != 0 || strcmp(disciplinaDep, "FIM") != 0)
        {
            inserePreReqNaLista(&lista, preReq, disciplinaDep);
            scanf("%s %s", preReq, disciplinaDep);
        }
        printf("\n");

        imprimeLista(&lista, numDis);
    }

    return 0;
}

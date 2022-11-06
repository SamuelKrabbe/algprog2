/**************************************************
2 *
3 * Alunos: Samuel Krabbe e Leonardo Perin
4 * Trabalho 1
5 * Professor: Marco Stefanes
6 *
7 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "util.h"
#define MAX 61
#define MIN 5


int main(void)
{
    int testCases;
    
    scanf("%d", &testCases);

    for (int i = 0; i < testCases; i++)
    {
        //células
        Subject firstSubjectRead, *subjectPointer;
        subjectPointer = &firstSubjectRead;

        //variáveis
        char courseName[MAX], dependencyCode[MIN], currentSubjectInAnalysis;
        int numOfSubjectsInCourse, dependencyIndex;

        scanf("%s", courseName);
        scanf("%d", &numOfSubjectsInCourse);

        //lendo as disciplinas e seus códigos respectivos
        for (int j = 0; j < numOfSubjectsInCourse; j++)
        {
            subjectPointer->indexOfCell = j;
            scanf("%s %s", subjectPointer->code, subjectPointer->name);
            
            createNewSubjectCell(subjectPointer);
        }

        //setando o número de dependências para 0 em todas as células
        for (int r = 0; r < numOfSubjectsInCourse; r++)
        {
            subjectPointer->indexOfCell = 0;
            subjectPointer = subjectPointer->nextCell;
        }

        //lendo as dependências
        while (scanf("%s %s", dependencyCode, currentSubjectInAnalysis) != "FIM FIM")
        {
            for (int k = 0; k < numOfSubjectsInCourse; k++)
            {
                if (currentSubjectInAnalysis == subjectPointer->code)
                {
                    dependencyIndex = getSubjectIndex(dependencyCode, subjectPointer, numOfSubjectsInCourse);
                    linkDependencyIndexToCell(dependencyIndex, subjectPointer, subjectPointer->numOfDependencies);
                }
                else
                {
                    subjectPointer = subjectPointer->nextCell;
                }
            }
        }

        for (int s = 0; s < numOfSubjectsInCourse; s++)
        {
            printf("%d", subjectPointer->indexOfCell);
            printf("%s", subjectPointer->code);
            printf("%s", subjectPointer->name);
            printf("%d", subjectPointer->numOfDependencies);
            for (int g = 0; g < subjectPointer->numOfDependencies; g++)
                printf("%d", subjectPointer->dependenciesIndex[g]);
        }
    }
    return 0;
}
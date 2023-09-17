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
#define CONST 1


int main(void)
{
    int testCases;
    char endOfTest[] = {'F', 'I', 'M', '\0'};

    scanf("%d", &testCases);

    for (int i = 0; i < testCases; i++)
    {
        //c�lulas
        Subject firstSubRead, *subPointer;
        subPointer = &firstSubRead;

        //vari�veis
        char courseName[MAX], dependencyCode[MIN], currentSubInAnalysis[MIN];
        int numOfSubsInCourse, dependencyIndex, flag1, flag2;

        scanf("%s", courseName);
        scanf("%d", &numOfSubsInCourse);

        //lendo as disciplinas e seus c�digos respectivos
        for (int j = 0; j < numOfSubsInCourse; j++)
        {
            subPointer->indexOfCell = j;
            scanf("%s %s", subPointer->code, subPointer->name);

            addNewCellToList(subPointer);
        }
        subPointer->nextCell = &firstSubRead;

        //setando o n�mero de depend�ncias para 0 em todas as c�lulas
        for (int r = 0; r < numOfSubsInCourse; r++)
        {
            subPointer->indexOfCell = 0;
            subPointer = subPointer->nextCell;
        }

        //lendo as depend�ncias
        while (CONST)
        {
            scanf("%s %s", dependencyCode, currentSubInAnalysis);

            flag1 = compareStrings(dependencyCode, endOfTest);
            flag2 = compareStrings(currentSubInAnalysis, endOfTest);

            if (flag1 && flag2)
                break;

            for (int k = 0; k < numOfSubsInCourse; k++)
            {
                if (currentSubInAnalysis == subPointer->code)
                {
                    dependencyIndex = getSubjectIndex(dependencyCode, subPointer, numOfSubsInCourse);
                    linkDependencyIndexToCell(dependencyIndex, subPointer, subPointer->numOfDependencies);
                }
                else
                {
                    subPointer = subPointer->nextCell;
                }
            }
        }

        for (int s = 0; s < numOfSubsInCourse; s++)
        {
            printf("%d", subPointer->indexOfCell);
            printf("%s", subPointer->code);
            printf("%s", subPointer->name);
            printf("%d", subPointer->numOfDependencies);
            for (int g = 0; g < subPointer->numOfDependencies; g++)
                printf("%d", subPointer->dependenciesIndex[g]);
        }
    }
    return 0;
}

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

// typedef struct subjectCell
// {
//     int indexOfCell;
//     char code[MIN];
//     char name[MAX];
//     int numOfDependencies;
//     int dependenciesIndex[INT_MAX];
//     struct subjectCell *nextCell;
// }Subject;

int main(void)
{
    int testCases;
    char endOfTest[] = {'F', 'I', 'M', '\0'};
    
    scanf("%d", &testCases);
    printf("\n");

    //executa para cada caso de teste
    for (int i = 0; i < testCases; i++)
    {
        //criando lista encadeada com cabeça
        Subject firstsubjectRead, *subjectPointer;
        firstsubjectRead.nextCell = NULL;
        subjectPointer = &firstsubjectRead;

        //variáveis
        char courseName[MAX], dependencyCode[MIN], currentsubjectInAnalysis[MIN];
        int numOfsubjectsInCourse, dependencyIndex, flag1, flag2;

        //lendo o nome do curso e número de disciplinas nele
        scanf("%s", courseName);
        scanf("%d", &numOfsubjectsInCourse);

        //lendo as disciplinas e seus códigos respectivos
        for (int j = 0, r = 0; j < numOfsubjectsInCourse; j++, r--)
        {
            subjectPointer->indexOfCell = j;
            subjectPointer->numOfDependencies = j - r;
            
            scanf("%s %s", subjectPointer->code, subjectPointer->name);
            
            addNewCellToList(subjectPointer);
        }
        subjectPointer->nextCell = &firstsubjectRead;

        //lendo as dependências
        while (CONST)
        {
            scanf("%s %s", dependencyCode, currentsubjectInAnalysis);

            flag1 = compareStrings(dependencyCode, endOfTest);
            flag2 = compareStrings(currentsubjectInAnalysis, endOfTest);

            //se as duas flags forem iguais a 'FIM'(= 1) o teste para
            if (flag1 && flag2)
                break;

            for (int k = 0; k < numOfsubjectsInCourse; k++)
            {
                if (currentsubjectInAnalysis == subjectPointer->code)
                {
                    dependencyIndex = getSubjectIndex(dependencyCode, subjectPointer, numOfsubjectsInCourse);
                    linkDependencyIndexToCell(dependencyIndex, subjectPointer, subjectPointer->numOfDependencies);
                }
                else
                    subjectPointer = subjectPointer->nextCell;
            }
        }
        printf("\n");

        for (int s = 0; s < numOfsubjectsInCourse; s++)
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
/**************************************************
2 *
3 * Aluno: Samuel Krabbe
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

typedef struct
{
    int indexOfCell;
    char code[MIN];
    char name[MAX];
    int numOfDependencies;
    Subject *nextCell;
}Subject;

typedef struct
{
    char code[MIN];
    int indexesDependent[INT_MAX];
    Subject *nextCell;
}Dependency;

// int vectorLenght(char *vector)
// {}

int main(void)
{
    int testCases;
    
    scanf("%d", &testCases);

    for (int i = 0; i < testCases; i++)
    {
        Subject firstSubjectRead, *subjectPointer;
        Dependency firstDependencyRead, *dependencyPointer;
        subjectPointer = &firstSubjectRead;
        dependencyPointer = &firstDependencyRead;

        char courseName[MAX], dependencyCode[MIN], currentSubjectInAnalysis;
        int numOfSubjectsInCourse;

        scanf("%s", courseName);
        scanf("%d", &numOfSubjectsInCourse);

        //lendo as disciplinas e seus códigos respectivos
        for (int j = 0; j < numOfSubjectsInCourse; j++)
        {
            subjectPointer->indexOfCell = j;
            scanf("%s %s", subjectPointer->code, subjectPointer->name);
            
            //criando nova célula, faça uma função disso
            Subject newSubjectCell;
            subjectPointer->nextCell = &newSubjectCell;
            subjectPointer = subjectPointer->nextCell;
        }

        //lendo as dependências/pré-requisitos
        while (scanf("%s %s", dependencyCode, currentSubjectInAnalysis) != "FIM FIM")
        {
            for (int k = 0; k < numOfSubjectsInCourse; k++)
            {
                if (currentSubjectInAnalysis == subjectPointer->code)
                {
                    // dependencyPointer->code = dependencyCode;

                    dependencyPointer->indexesDependent[k] = subjectPointer->indexOfCell;

                    //criando nova célula, faça uma função disso
                    Dependency newDependencyCell;
                    dependencyPointer->nextCell = &newDependencyCell;
                    dependencyPointer = dependencyPointer->nextCell;
                    break;
                }
                else
                {
                    subjectPointer = subjectPointer->nextCell;
                }
            }
        }
    }
    
    return 0;
}
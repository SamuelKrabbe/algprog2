#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 61
#define MIN 5
#define CONST 1

typedef struct subjectCell
{
    int indexOfCell;
    char code[MIN];
    char name[MAX];
    int numOfDependencies;
    int dependenciesIndex[INT_MAX];
    struct subjectCell *nextCell;
}Subject;


int main(void)
{
    //variáveis
   char courseName[MAX];
   int testCases, i, numOfSubsInCourse;

    //células
    Subject firstSubRead, *subPointer;
    subPointer = &firstSubRead;

    scanf("%d", &testCases);

    for (i = 0; i < testCases; i++)
    {
        scanf("%s", courseName);
        scanf("%d", &numOfSubsInCourse);
    }
    return 0;
}
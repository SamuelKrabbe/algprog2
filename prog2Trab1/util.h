
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 61
#define MIN 5

//tipo "Subject" -------------------------------------------

typedef struct subjectCell
{
    int indexOfCell;
    char code[MIN];
    char name[MAX];
    int numOfDependencies;
    int dependenciesIndex[INT_MAX];
    struct subjectCell *nextCell;
}Subject;


//FUNÇÕES ----------------------------------------------------

int compareStrings(char *string1, char *string2)
{
    int i = 0;

    while ((*(string1 + i) != '\0') || (*(string2 + i) != '\0'))
    {
        if (*(string1 + i) != *(string2 + i))
            return 0;
        else
            i++;
    }
    return 1;
}

void addNewCellToList(Subject *cellPointer)
{
    Subject newSubjectCell;
    cellPointer->nextCell = &newSubjectCell;
    cellPointer = cellPointer->nextCell;
}

int getSubjectIndex(char *dependencyCode, Subject *cellPointer, int numOfSubjectsInCourse)
{
    int status;

    for (int i = 0; i < numOfSubjectsInCourse; i++)
    {
        for (int j = 0; j < MIN; j++)
            if (cellPointer->code[j] != *(dependencyCode + j))
            {
                status = 0;
                break;
            }
            else
                status = 1;

        if (status == 0)
            cellPointer = cellPointer->nextCell;
        else
            return cellPointer->indexOfCell;
    }
    return -1;
}

void linkDependencyIndexToCell(int dependencyIndex, Subject *cellPointer, int numOfDependencies)
{
    cellPointer->dependenciesIndex[numOfDependencies] = dependencyIndex;
    cellPointer->numOfDependencies++;
}

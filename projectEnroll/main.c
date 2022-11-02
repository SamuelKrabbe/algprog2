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

struct subjectCell
{
    char code[MIN];
    char name[MAX];
    char dependencies[INT_MAX][MIN];
    int numOfDependencies;
    struct subjectCell *next;
};

// int vectorLenght(char *vector)
// {}

int main(void)
{
    struct subjectCell firstSubject, *p; 
    char courseName[MAX], currentSubjectCode[MIN], currentSubjectDependency[MIN];
    int numOfSubjects;

    p = &firstSubject;

    scanf("%s", courseName);
    scanf("%d", &numOfSubjects);

    //lendo as disciplinas e seus códigos
    for (int i = 0; i < numOfSubjects; i++)
    {
        scanf("%s %s", p->code, p->name);

        if (i != (numOfSubjects - 1))
        {
            //possível função
            struct subjectCell newSubject;
            p->next = &newSubject;
            p = p->next;
        }else{
            p->next = &firstSubject;
            p = p->next;
        }
    }


    //lendo as dependencias
    while (scanf("%s %s", currentSubjectDependency, currentSubjectCode) != "FIM FIM")
    {
        for (int j = 0; j < numOfSubjects; j++)
        {
            if (currentSubjectCode == p->code)
            {   
                // p->numOfDependencies = vectorLenght(p->dependencies);
                // p->dependencies[p->numOfDependencies] = currentSubjectDependency;
            }else{
                p = p->next;
            }
        }
    }
    
    return 0;
}
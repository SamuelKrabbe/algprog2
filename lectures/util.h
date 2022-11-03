#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//aula23---------------------------------------------------------------------------------------------------
typedef struct stack
{
    char content;
    struct stack *next;
} Stack;

void stackListWithHead(char x, Stack *top)
{
    Stack *newStack;

    newStack = (Stack *)malloc(sizeof(Stack));

    newStack->content = x;
    newStack->next = top->next;
    top->next = newStack;
}

char unstackListWithHead(Stack *top)
{
    char x;
    Stack *p;

    if (top->next != NULL)
    {
        p = top->next;
        x = p->content;
        top->next = p->next;
        free(p);
        return x;
    }
    else
    {
        printf("Pilha vaia!\n");
        return ' ';
    }
}
---------------------------------------------------------------------------------------------------------------

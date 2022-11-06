#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "util.h"

int main(void)
{
    char word[100], aux;
    Stack *top;

    top->next = NULL;

    scanf("%s", word);

    for (int i = 0; word[i] != '\0'; i++)
    {
        stackListWithHead(word[i], top);
    }

    for (int j = 0; word[j] != '\0'; j++)
    {
        aux = unstackListWithHead(top);

        if (aux != word[j])
        {
            printf("Não é palíndromo!");
            break;
        }
    }
    printf("É palíndromo!\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(void)
{
    char firstName[7] = {'s', 'a', 'm', 'u', 'e', 'l', '\0'}, lastName[7] = {'k', 'r', 'a', 'b', 'b', 'e', '\0'};

    //letra a
    uppercaseUsingArray(firstName);

    for (int i = 0; firstName[i] != '\0'; i++)
        printf("%c", firstName[i]);
    printf("\n");

    //letra b
    uppercaseUsingPointer(lastName);

    for (int i = 0; *(lastName + i) != '\0'; i++)
        printf("%c", *(lastName + i));
    printf("\n");

    return 0;
}

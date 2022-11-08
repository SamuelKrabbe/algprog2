#include <stdio.h>
#include <stdlib.h>

//letra a
void uppercaseUsingArray(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
        if (string[i] > 65)
            string[i] = string[i] - 32;
}

//letra b
void uppercaseUsingPointer(char *string)
{
    for (int i = 0; *(string + i) != '\0'; i++)
        if (*(string + i) > 65)
            *(string + i) = *(string + i) - 32;
}
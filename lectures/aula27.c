#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define MAX 100

int main(void)
{
    char originalFile[MAX + 1], newFile[MAX + 1], uppercaseFile[MAX + 1];

    printf("Original file (with extension): ");
    scanf("%s", originalFile);
    
    printf("Name the new file to be copied (with extension): ");
    scanf("%s", newFile);

    printf("Name the uppercase file to be created (with extension): ");
    scanf("%s", uppercaseFile);

    copyOriginalToNewFile(originalFile, newFile);
    
    uppercaseOriginalToNewFile(originalFile, uppercaseFile);

    return 0;
}

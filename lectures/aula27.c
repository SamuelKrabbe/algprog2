#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define MAX 100

int main(void)
{
    char originalFile[MAX + 1], newFile[MAX + 1];

    printf("File to be copied: ");
    scanf("%s", originalFile);

    printf("Name the copy of the file: ");
    scanf("%s", newFile);

    copyOriginalToNewFile(originalFile, newFile);

    return 0;
}

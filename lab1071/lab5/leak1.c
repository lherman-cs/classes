/**  
    leak1.c  -  memory leak example

    This program will reserve a block of memory large enough
    to hold 100 characters.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *p = malloc(sizeof(char) * 100);
    
    strcpy(p, "Constantionople");
    printf("%s", p);
    free(p);
    return 0;
}


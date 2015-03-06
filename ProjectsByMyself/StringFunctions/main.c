#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[100], *pointer = NULL;
    printf("Enter the sentence: ");
    //gets(string);
    //puts(string);
    fgets(string, sizeof(string), stdin);
    puts(string);
    pointer = strtok(string, " .,!?");
    while(pointer)
    {
        printf("%s\n", pointer);
        pointer = strtok(NULL, " .,!?");
    }
    return 0;
}

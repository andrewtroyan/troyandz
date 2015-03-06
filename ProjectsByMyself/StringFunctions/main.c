#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[100] = "Hello my world!", *pointer = NULL;
    pointer = strtok(string, " !");
    while(pointer)
    {
        printf("%s\n", pointer);
        pointer = strtok(NULL, " !");
    }
    return 0;
}

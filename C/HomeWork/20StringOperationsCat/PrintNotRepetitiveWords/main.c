#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main()
{
    FILE *filePointer;
    char str[SIZE], strPrinted[SIZE], *strTemp;

    filePointer = fopen("../ExampleOfText.txt", "r");
    if(filePointer == NULL)
    {
        fprintf(stderr, "Cannot open the file.\n");
        exit(1);
    }

    while(fgets(str, sizeof(str), filePointer))
    {
        strTemp = strtok(str, " .,-;!?\"\n");
        while(strTemp)
        {
            if(strstr(strPrinted, strTemp) == NULL && *strTemp == *(strTemp + strlen(strTemp) - 1))
            {
                strcat(strPrinted, strTemp);
                strcat(strPrinted, " ");
                puts(strTemp);
            }
            strTemp = strtok(NULL, " .,-;!?\"\n");
        }
    }

    fclose(filePointer);

    return 0;
}

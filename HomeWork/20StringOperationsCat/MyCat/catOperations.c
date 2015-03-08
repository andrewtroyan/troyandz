#include "catOperations.h"

void printNumbers(char **argv, FILE *filePointer, char *strTemp)
{
    int counter = 1;

    for(int i = 2; argv[i] != NULL; ++i)
    {
        filePointer = fopen(argv[i], "r");
        if(filePointer == NULL)
        {
            fprintf(stderr, "%s: No such file or directory.\n", argv[i]);
        }
        else
        {
            while(fgets(strTemp, SIZE * sizeof(strTemp), filePointer))
            {
                printf("%6d  %s", counter++, strTemp);
            }
            fclose(filePointer);
        }
    }
}

void printNumbersNonBlanks(char **argv, FILE *filePointer, char *strTemp)
{
    int counter = 1;

    for(int i = 2; argv[i] != NULL; ++i)
    {
        filePointer = fopen(argv[i], "r");
        if(filePointer == NULL)
        {
            fprintf(stderr, "%s: No such file or directory.\n", argv[i]);
        }
        else
        {
            while(fgets(strTemp, SIZE * sizeof(strTemp), filePointer))
            {
                if(strlen(strTemp) > 1)
                {
                    printf("%6d  %s", counter++, strTemp);
                }
                else
                {
                    printf("%8s%s", "", strTemp);
                }
            }
            fclose(filePointer);
        }
    }
}

void printHelp(FILE *filePointer, char *strTemp)
{
    filePointer = fopen("/home/troyan/andrewtroyan/troyandz/HomeWork/20StringOperationsCat/MyCat/CatInstructions.txt", "r");
    if(filePointer == NULL)
    {
        fprintf(stderr, "Access error.\n");
        exit(1);
    }
    while(fgets(strTemp, SIZE * sizeof(strTemp), filePointer))
    {
        printf("%s", strTemp);
    }
    fclose(filePointer);
}

void catFiles(char **argv, FILE *filePointer, char *strTemp)
{
    for(int i = 1; argv[i] != NULL; ++i)
    {
        filePointer = fopen(argv[i], "r");
        if(filePointer == NULL)
        {
            fprintf(stderr, "%s: No such file or directory.\n", argv[i]);
        }
        else
        {
            while(fgets(strTemp, SIZE * sizeof(strTemp), filePointer))
            {
                printf("%s", strTemp);
            }
            fclose(filePointer);
        }
    }
}

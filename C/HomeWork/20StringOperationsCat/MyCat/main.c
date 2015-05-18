#include "catOperations.h"

int main(int argc, char **argv)
{
    FILE *filePointer;
    char *strTemp = NULL;

    strTemp = (char *)malloc(SIZE * sizeof(char));
    if(strTemp == NULL)
    {
        fprintf(stderr, "Memory error.\n");
        exit(1);
    }

    if(argc > 1)
    {
        if(strstr(argv[1], "--"))
        {
            if(strstr(argv[1], "help"))
            {
                printHelp(filePointer, strTemp);
            }
            else if(strstr(argv[1], "number"))
            {
                printNumbers(argv, filePointer, strTemp);
            }
            else if(strstr(argv[1], "number-nonblank"))
            {
                printNumbersNonBlanks(argv, filePointer, strTemp);
            }
            else if(strstr(argv[1], "show-ends"))
            {
                showEnds(argv, filePointer, strTemp);
            }
            else if(strstr(argv[1], "squeeze-blank"))
            {
                squeezeBlanks(argv, filePointer, strTemp);
            }
        }
        else if(strchr(argv[1], '-'))
        {
            if(strchr(argv[1], 'n'))
            {
                printNumbers(argv, filePointer, strTemp);
            }
            if(strchr(argv[1], 'b'))
            {
                printNumbersNonBlanks(argv, filePointer, strTemp);
            }
            if(strchr(argv[1], 'E'))
            {
                showEnds(argv, filePointer, strTemp);
            }
            if(strchr(argv[1], 's'))
            {
                squeezeBlanks(argv, filePointer, strTemp);
            }
            if(strcmp(argv[1], "-") == 0)
            {
                gets(strTemp);
                printf("%s\n", strTemp);
            }
        }
        else
        {
            catFiles(argv, filePointer, strTemp);
        }
    }
    else
    {
        gets(strTemp);
        printf("%s\n", strTemp);
    }

    free(strTemp);
    strTemp = NULL;

    return 0;
}

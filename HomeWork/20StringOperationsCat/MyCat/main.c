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
            if(strstr(argv[1], "number"))
            {
                printNumbers(argv, filePointer, strTemp);
            }
            if(strstr(argv[1], "number-nonblank"))
            {
                printNumbersNonBlanks(argv, filePointer, strTemp);
            }
        }
        else if(strchr(argv[1], '-'))
        {
            if(strchr(argv[1], 'b'))
            {
                printNumbersNonBlanks(argv, filePointer, strTemp);
                return 0;
            }
            if(strchr(argv[1], 'n'))
            {
                printNumbers(argv, filePointer, strTemp);
            }
        }
        else if(strchr(argv[1], ' ') == 0)
        {
            catFiles(argv, filePointer, strTemp);
        }
    }

    free(strTemp);
    strTemp = NULL;
    return 0;
}

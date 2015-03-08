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
        if(strcmp(argv[1], "--number") == 0 || strcmp(argv[1], "-n") == 0)
        {
            printNumbers(argv, filePointer, strTemp);
        }
        else if(strcmp(argv[1], "-b") == 0 || strcmp(argv[1], "--number-nonblank") == 0 || strcmp(argv[1], "-nb") == 0 || strcmp(argv[1], "-bn") == 0)
        {
            printNumbersNonBlanks(argv, filePointer, strTemp);
        }
        else if(strcmp(argv[1], "--help") == 0)
        {
            printHelp(filePointer, strTemp);
        }
        else
        {
            catFiles(argv, filePointer, strTemp);
        }
    }

    free(strTemp);
    strTemp = NULL;
    return 0;
}

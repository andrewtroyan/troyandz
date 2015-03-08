#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char **argv)
{
    FILE *filePointer;
    char strTemp[SIZE];

    if(argc > 1)
    {
        if(strcmp(argv[1], "--number") == 0 || strcmp(argv[1], "-n") == 0)
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
                    while(fgets(strTemp, sizeof(strTemp), filePointer))
                    {
                        printf("%6d  %s", counter, strTemp);
                        ++counter;
                    }
                    fclose(filePointer);
                }
            }
        }
        else if(strcmp(argv[1], "--help") == 0)
        {
            filePointer = fopen("/home/troyan/andrewtroyan/troyandz/HomeWork/20StringOperationsCat/MyCat/CatInstructions.txt", "r");
            if(filePointer == NULL)
            {
                fprintf(stderr, "Access error.\n");
                exit(1);
            }
            while(fgets(strTemp, sizeof(strTemp), filePointer))
            {
                puts(strTemp);
            }
            fclose(filePointer);
        }
        else
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
                    while(fgets(strTemp, sizeof(strTemp), filePointer))
                    {
                        printf("%s", strTemp);
                    }
                    fclose(filePointer);
                }
            }
        }
    }
    return 0;
}

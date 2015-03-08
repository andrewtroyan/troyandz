#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        if(strcmp(argv[1], "--number") == 0 || strcmp(argv[1], "-n") == 0)
        {
            FILE *filePoint;
            char strTemp[SIZE];
            int counter = 1;
            for(int i = 2; argv[i] != NULL; ++i)
            {
                filePoint = fopen(argv[i], "r");
                if(filePoint == NULL)
                {
                    fprintf(stderr, "No such file or directory.\n");
                    exit(1);
                }
                while(fgets(strTemp, sizeof(strTemp), filePoint))
                {
                    printf("%6d  %s", counter, strTemp);
                    ++counter;
                }
                fclose(filePoint);
            }
        }
    }
    return 0;
}

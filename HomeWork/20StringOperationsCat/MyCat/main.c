#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        if(strcmp(argv[1], "--number") == 0)
        {
            if(argv[2] != NULL)
            {
                FILE *filePoint;
                char strTemp[SIZE];
                filePoint = fopen(argv[2], "r");
                if(filePoint == NULL)
                {
                    fprintf(stderr, "Cannot open the file.\n");
                    exit(1);
                }
                for(int i = 1; fgets(strTemp, sizeof(strTemp), filePoint); ++i)
                {
                    printf("%6d %s", i, strTemp);
                }
                fclose(filePoint);
            }
        }
    }
    return 0;
}

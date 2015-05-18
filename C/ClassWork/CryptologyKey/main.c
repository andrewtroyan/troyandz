#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *filepointer = NULL;
    filepointer = fopen(argv[1], "b");
    if(!filepointer)
    {
        fprintf(stderr, "Can't open the file.\n");
        exit(1);
    }

    fseek(filepointer, 0, SEEK_END);
    int fileSize = ftell(filepointer);
    rewind(filepointer);

    char *storage = (char *)malloc(fileSize * sizeof(char));
    if(!storage)
    {
        fprintf(stderr, "Memory error.\n");
        fclose(filepointer);
        exit(1);
    }
    memcpy(storage, filepointer, fileSize);
    fclose(filepointer);

    free(storage);
    storage = NULL;
    return 0;
}

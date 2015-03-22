#include "ShortestWaySearch.h"

int main()
{
    FILE *filepointer = NULL;
    filepointer = fopen("Example.txt", "r");
    if(filepointer == NULL)
    {
        fprintf(stderr, "Cannot open the file.\n");
        exit(1);
    }
// -----
    int amountOfNodes, amountOfEdges, from, to;
    fscanf(filepointer, "%d %d\n%d %d\n", &amountOfNodes, &amountOfEdges, &from, &to);
//-----

    fclose(filepointer);
    return 0;
}

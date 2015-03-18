#include "Depth.h"

int main()
{
    int amountOfNodes, amountOfEdges;
    FILE *filepoint;

    filepoint = fopen("EdgesAndNodes.txt", "r");
    if(filepoint == NULL)
    {
        fprintf(stderr, "Cannot open the file.\n");
        exit(1);
    }

    fscanf(filepoint, "%d %d\n", &amountOfNodes, &amountOfEdges); // считываем кол-во вершин и кол-во рёбер

    // -----

    List *listOfNodes = NULL;
    listOfNodes = (List *)malloc(amountOfNodes * sizeof(List)); // заводим массив списков
    if(listOfNodes == NULL)
    {
        fclose(filepoint);
        fprintf(stderr, "Memory error.\n");
        exit(1);
    }

    // -----

    State *arrayOfStates = NULL;
    arrayOfStates = (State *)malloc(amountOfNodes * sizeof(State)); // заводим массив с состоянием вершин (посетили, не посетили)
    if(arrayOfStates == NULL)
    {
        fclose(filepoint);
        free(listOfNodes);
        listOfNodes = NULL;
        fprintf(stderr, "Memory error.\n");
        exit(1);
    }

    for(int i = 0; i < amountOfNodes; ++i)
    {
        arrayOfStates[i] = unflagged; // помечаем вершины как не посещенные
    }
    // -----

    int temp1, temp2;
    for(int i = 0; i < amountOfEdges; ++i)
    {
        fscanf(filepoint, "%d %d\n", &temp1, &temp2);
        addToList(temp2 - 1, &(listOfNodes[temp1 - 1])); // заносим вершины в массив
        addToList(temp1 - 1, &(listOfNodes[temp2 - 1]));
    }

    // -----

/*    for(int i = 0; i < amountOfNodes; ++i)
    {
        printf("%d - ", i + 1);
        printList(listOfNodes[i]);
        printf("\n");
    } */

    // -----

    free(listOfNodes);
    listOfNodes = NULL;
    free(arrayOfStates);
    arrayOfStates = NULL;
    fclose(filepoint);
}

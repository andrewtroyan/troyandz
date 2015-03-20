#include "DynamicDataStructuresFunctions.h"

int main()
{
    FILE *filepoint;
    filepoint = fopen("EdgesAndNodes.txt", "r");
    if(filepoint == NULL)
    {
        fprintf(stderr, "Cannot open the file.\n");
        exit(1);
    }

    // -----

    int amountOfNodes, amountOfEdges;
    fscanf(filepoint, "%d %d\n", &amountOfNodes, &amountOfEdges); // считываем кол-во вершин и кол-во рёбер

    // -----

    List *arrayOfLists = NULL;
    arrayOfLists = (List *)malloc(amountOfNodes * sizeof(List)); // заводим массив списков
    if(arrayOfLists == NULL)
    {
        fclose(filepoint);
        fprintf(stderr, "Memory error.\n");
        exit(1);
    }

    for(int i = 0; i < amountOfNodes; ++i)
    {
        initializeList(&arrayOfLists[i]); // инициализируем списки в массиве
    }

    int temp1, temp2;
    for(int i = 0; i < amountOfEdges; ++i)
    {
        fscanf(filepoint, "%d %d\n", &temp1, &temp2);
        addToList(temp2 - 1, &(arrayOfLists[temp1 - 1])); // заносим смежные вершины в наш массив списков (формируем граф)
        addToList(temp1 - 1, &(arrayOfLists[temp2 - 1]));
    }

    // -----

    State *arrayOfStates = NULL;
    arrayOfStates = (State *)malloc(amountOfNodes * sizeof(State)); // заводим массив с состоянием вершин (посетили, не посетили)
    if(arrayOfStates == NULL)
    {
        fclose(filepoint);
        for(int i = 0; i < amountOfNodes; ++i)
        {
            clearTheList(&arrayOfLists[i]);
        }
        free(arrayOfLists);
        arrayOfLists = NULL;
        fprintf(stderr, "Memory error.\n");
        exit(1);
    }

    for(int i = 0; i < amountOfNodes; ++i)
    {
        arrayOfStates[i] = unflagged; // помечаем вершины как не посещенные
    }

    // -----

    List listForWay = NULL; // создаем список, где будем отмечать наш путь
    int answer, firstNode; // firstNode - вершина, с которой мы начнем наш путь

    do
    {
        system("clear");
        printf("Enter the way of search:\n1. Depth.\n2. Width.\nAnswer: ");
        scanf("%d", &answer);
    }
    while(answer < 1 || answer > 2);

    do
    {
        system("clear");
        printf("Enter the number of node to start (1 - %d): ", amountOfNodes);
        scanf("%d", &firstNode);
    }
    while(firstNode < 1 || firstNode > amountOfNodes);

    if(answer == 1)
    {
        workOnStack(firstNode, arrayOfStates, arrayOfLists, &listForWay); // для обхода в глубину работаем со стеком
    }
    else if(answer == 2)
    {
        workOnQueue(firstNode, arrayOfStates, arrayOfLists, &listForWay); // для обхода в глубину работаем с очередью
    }

    // -----

    showList(listForWay); // показываем наш путь

    // -----

    fclose(filepoint);
    clearStructures(&arrayOfLists, amountOfNodes, &listForWay, &arrayOfStates); // очищаем массив списков, список пути и массива состояний

    return 0;
}

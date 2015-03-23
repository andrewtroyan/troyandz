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
// -----
    ListOfAlliedNodes *graph = (ListOfAlliedNodes *)malloc(amountOfNodes * sizeof(ListOfAlliedNodes));
    if(graph == NULL)
    {
        fclose(filepointer);
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    for(int i = 0; i < amountOfNodes; ++i)
    {
        graph[i] = NULL;
    }
// -----
    int node1, node2, weightOfEdge;
    for(int i = 0; i < amountOfEdges; ++i)
    {
        fscanf(filepointer, "%d %d %d\n", &node1, &node2, &weightOfEdge);
        addToListOfAlliedNodes(node1 - 1, weightOfEdge, &graph[node2 - 1]);
        addToListOfAlliedNodes(node2 - 1, weightOfEdge, &graph[node1 - 1]);
    }
// -----
    ListOfAlliedNodes temp = NULL;
    for(int i = 0; i < amountOfNodes; ++i)
    {
        temp = graph[i];
        printf("%d: ", i + 1);
        while(temp)
        {
            printf("%d - %d, ", temp->NodeToAlly.node + 1, temp->NodeToAlly.weightOfEdge);
            temp = temp->link;
        }
        printf("\b\b.\n");
    }
// -----
    NodeForAnalyze *listToAnalyze = (NodeForAnalyze *)malloc(amountOfNodes * sizeof(NodeForAnalyze));
    if(listToAnalyze == NULL)
    {
        fclose(filepointer);
        for(int i = 0; i < amountOfNodes; ++i)
        {
            clearListOfAlliedNodes(&graph[i]);
        }
        free(graph);
        graph = NULL;
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    initializeAnalyzeList(listToAnalyze, amountOfNodes, from);
    analyze(graph, listToAnalyze, amountOfNodes, to);
// -----
    int *stack = NULL, top = -1;
    stack = (int *)malloc(amountOfNodes * sizeof(int));
    if(stack == NULL)
    {
        fclose(filepointer);
        for(int i = 0; i < amountOfNodes; ++i)
        {
            clearListOfAlliedNodes(&graph[i]);
        }
        free(graph);
        graph = NULL;
        free(listToAnalyze);
        listToAnalyze = NULL;
        printf("No free memory.\n");
        exit(1);
    }

    push(stack, &top, to - 1);
    for(int i = to - 1; i != from - 1; )
    {
        push(stack, &top, listToAnalyze[i].from);
        i = listToAnalyze[i].from;
    }
// -----
    printf("Your way: ");
    while(!isEmpty(top))
    {
        printf("%d -> ", onTop(stack, top) + 1);
        pop(stack, &top);
    }
    printf("\b\b\b\b.   \n");
// -----
    for(int i = 0; i < amountOfNodes; ++i)
    {
        clearListOfAlliedNodes(&graph[i]);
    }
    free(graph);
    graph = NULL;
    free(listToAnalyze);
    listToAnalyze = NULL;
    free(stack);
    stack = NULL;
    fclose(filepointer);
    return 0;
}

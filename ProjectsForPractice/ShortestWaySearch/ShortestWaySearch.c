#include "ShortestWaySearch.h"

bool addToListOfAlliedNodes(int node, int weightOfEdge, ListOfAlliedNodes *pointer)
{
    AlliedNode *temp = NULL, *tempPointer = *pointer;
    temp = (AlliedNode *)malloc(sizeof(AlliedNode));
    if(temp == NULL)
    {
        return false;
    }
    temp->NodeToAlly.node = node;
    temp->NodeToAlly.weightOfEdge = weightOfEdge;
    temp->link = NULL;
    if(!tempPointer)
        *pointer = temp;
    else
    {
        while(tempPointer->link)
            tempPointer = tempPointer->link;
        tempPointer->link = temp;
    }
    temp = NULL;
    tempPointer = NULL;
    return true;
}

void clearListOfAlliedNodes(ListOfAlliedNodes *pointer)
{
    if(*pointer)
    {
        AlliedNode *temp = *pointer;
        while(*pointer)
        {
            temp = (*pointer)->link;
            (*pointer)->NodeToAlly.node = 0;
            (*pointer)->NodeToAlly.weightOfEdge = 0;
            free(*pointer);
            *pointer = temp;
        }
    }
}

// ------

void initializeAnalyzeList(NodeForAnalyze *array, int amountOfNodes, int from)
{
    for(int i = 0; i < amountOfNodes; ++ i)
    {
        if(i == from - 1)
        {
            array[i].destination = 0;
        }
        else
        {
            array[i].destination = INT_MAX;
        }
        array[i].from = -1;
        array[i].indicator = unflagged;
    }
}

int minOfAnalyzeList(NodeForAnalyze *array, int amountOfNodes)
{
    int min = INT_MAX, node = -1;
    for(int i = 0; i < amountOfNodes; ++i)
    {
        if(array[i].destination < min && array[i].indicator == unflagged)
        {
            node = i;
            min = array[i].destination;
        }
    }
    return node;
}

void analyze(ListOfAlliedNodes *graph, NodeForAnalyze *analyzeArray, int amountOfNodes, int to)
{
    int min = minOfAnalyzeList(analyzeArray, amountOfNodes);
    if(min != to - 1)
    {
        ListOfAlliedNodes temp = graph[min];
        while(temp)
        {
            if(analyzeArray[min].destination + temp->NodeToAlly.weightOfEdge < analyzeArray[temp->NodeToAlly.node].destination)
            {
                analyzeArray[temp->NodeToAlly.node].destination = analyzeArray[min].destination + temp->NodeToAlly.weightOfEdge;
                analyzeArray[temp->NodeToAlly.node].from = min;
            }
            temp = temp->link;
        }
        analyzeArray[min].indicator = flagged;
        analyze(graph, analyzeArray, amountOfNodes, to);
    }
}

// -----

void push(int *stack, int *top, int value)
{
    stack[(++(*top))] = value;
}

bool isEmpty(int top)
{
    return top == -1;
}

void pop(int *stack, int *top)
{
    if(*top > -1)
    {
        stack[(*top)--] = 0;
    }
}

void clearStack(int *stack, int *top)
{
    while(!isEmpty(*top))
        pop(stack, top);
}

int onTop(int *stack, int top)
{
    return stack[top];
}

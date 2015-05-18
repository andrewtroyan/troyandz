#include "DynamicDataStructuresFunctions.h"

void showList(List pointer)
{
    printf("Your way: ");
    List temp = pointer;
    while(temp)
    {
        printf("%d -> ", temp->data + 1);
        temp = temp->link;
    }
    printf("\b\b\b\b%s\n", ".   ");
}

void clearStructures(List **arrayOfLists, int amountOfNodes, List *ListForWay, State **arrayOfStates)
{
    for(int i = 0; i < amountOfNodes; ++i)
    {
        clearTheList(*arrayOfLists + i);
    }
    free(*arrayOfLists);
    *arrayOfLists = NULL;
    clearTheList(ListForWay);
    free(*arrayOfLists);
    *arrayOfLists = NULL;
    free(*arrayOfStates);
}

void workOnStack(int firstNode, State *arrayOfStates, List *arrayOfLists, List *listForWay)
{
    Stack stack = NULL;
    int temp;
    List tempList = NULL;
    pushToStack(firstNode - 1, &stack);
    arrayOfStates[firstNode - 1] = flagged;
    while(!isStackEmpty(stack))
    {
        onTopOfStack(&temp, stack);
        popFromStack(&stack);
        while(!addToList(temp, listForWay)) {}
        tempList = arrayOfLists[temp];
        while(tempList)
        {
            if(arrayOfStates[tempList->data] == unflagged)
            {
                while(!pushToStack(tempList->data, &stack)) {}
                arrayOfStates[tempList->data] = flagged;
            }
            tempList = tempList->link;
        }
    }
    clearStack(&stack);
}

void workOnQueue(int firstNode, State *arrayOfStates, List *arrayOfLists, List *listForWay)
{
    Queue queue;
    int temp;
    List tempList = NULL;
    initializeQueue(&queue);
    addToQueue(firstNode - 1, &queue);
    arrayOfStates[firstNode - 1] = flagged;
    while(!isQueueEmpty(queue))
    {
        onTopOfQueue(&temp, queue);
        popFromQueue(&queue);
        while(!addToList(temp, listForWay)) {}
        tempList = arrayOfLists[temp];
        while(tempList)
        {
            if(arrayOfStates[tempList->data] == unflagged)
            {
                while(!addToQueue(tempList->data, &queue)) {}
                arrayOfStates[tempList->data] = flagged;
            }
            tempList = tempList->link;
        }
    }
    clearQueue(&queue);
}

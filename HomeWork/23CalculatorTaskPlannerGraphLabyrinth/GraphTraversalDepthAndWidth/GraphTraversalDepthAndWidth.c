#include "Depth.h"

void initializeList(List *pointer)
{
    *pointer = NULL;
}

bool addToList(int data, List *pointer)
{
    List newData = NULL, tempPointer = *pointer;

    newData = (List)malloc(sizeof(Node));
    if(newData == NULL)
        return false;
    newData->data = data;
    newData->link = NULL;

    if(tempPointer == NULL)
        *pointer = newData;
    else
    {
        while(tempPointer->link != NULL)
            tempPointer = tempPointer->link;
        tempPointer->link = newData;
    }

    newData = NULL;
    return true;
}

void clearTheList(List *pointer)
{
    List tempPointer = *pointer;
    while(*pointer != NULL)
    {
        tempPointer = (*pointer)->link;
        free(*pointer);
        *pointer = tempPointer;
    }
}

void printList(List list)
{
    List temp = list;
    while(temp)
    {
        printf("%d ", (temp->data) + 1);
        temp = temp->link;
    }
}



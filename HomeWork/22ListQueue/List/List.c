#include "List.h"

void initializeList(List *pointer)
{
    *pointer = NULL;
}

bool addToList(Data data, List *pointer)
{
    List newData, tempPointer = *pointer;

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
    return true;
}

void clearTheList(List *pointer)
{
    List tempPointer = *pointer;
    while(*pointer != NULL)
    {
        tempPointer = (*pointer)->link;
        free(*pointer);
        *pointer = NULL;
        *pointer = tempPointer;
    }
}

bool isEmpty(const List pointer)
{
    return pointer == NULL;
}

bool isFull(const List pointer)
{
    List testPointer;
    bool indicator;

    testPointer = (List)malloc(sizeof(Node));
    if(testPointer == NULL)
        indicator = true;
    else
        indicator = false;
    free(testPointer);
    return indicator;
}

int amountOfNodes(const List pointer)
{
    int counter = 0;
    List tempPointer = pointer;

    while(tempPointer != NULL)
    {
        ++counter;
        tempPointer = tempPointer->link;
    }

    return counter;
}

void workOnNodes(const List pointer, void (*function)(Data data))
{
    List tempPointer = pointer;
    while(tempPointer != NULL)
    {
        function(tempPointer->data);
        tempPointer = tempPointer->link;
    }
}



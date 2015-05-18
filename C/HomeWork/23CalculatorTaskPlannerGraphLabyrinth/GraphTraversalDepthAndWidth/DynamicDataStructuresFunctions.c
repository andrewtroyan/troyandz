#include "DynamicDataStructuresFunctions.h"

// ---LIST---

void initializeList(List *pointer)
{
    *pointer = NULL;
}

bool addToList(int data, List *pointer)
{
    Node *newData = NULL, *tempPointer = *pointer;

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
    Node *tempPointer = *pointer;
    while(*pointer != NULL)
    {
        tempPointer = (*pointer)->link;
        free(*pointer);
        *pointer = tempPointer;
    }
}

// --- STACK ---

void initializeStack(Stack *pointer)
{
    *pointer = NULL;
}

bool pushToStack(int data, Stack *pointer)
{
    Node *temp = *pointer;
    temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL)
        return false;
    temp->data = data;
    temp->link = *pointer;

    *pointer = temp;
    temp = NULL;
    return true;
}

void popFromStack(Stack *pointer)
{
    if(*pointer)
    {
        Node *temp = *pointer;
        *pointer = (*pointer)->link;
        temp->data = 0;
        temp->link = NULL;
        free(temp);
        temp = NULL;
    }
}

bool isStackEmpty(Stack pointer)
{
    return !pointer;
}

bool onTopOfStack(int *data, Stack pointer)
{
    if(!isStackEmpty(pointer))
    {
        *data = pointer->data;
        return true;
    }
    return false;
}

void clearStack(Stack *pointer)
{
    while(*pointer)
        popFromStack(pointer);
}

// ---QUEUE---

void initializeQueue(Queue *pointer)
{
    pointer->head = NULL;
    pointer->tail = NULL;
}

bool addToQueue(int data, Queue *pointer)
{
    Node *temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL)
    {
        return false;
    }
    temp->data = data;
    temp->link = NULL;

    if(!(pointer->head))
    {
        pointer->head = temp;
        pointer->tail = temp;
    }
    else
    {
        pointer->tail->link = temp;
        pointer->tail = temp;
    }

    temp = NULL;
    return true;
}

void popFromQueue(Queue *pointer)
{
    if(pointer->head)
    {
        Node *temp = pointer->head;
        pointer->head = pointer->head->link;
        temp->data = 0;
        temp->link = NULL;
        free(temp);
        temp = NULL;

        if(!(pointer->head))
            pointer->tail = NULL;
    }
}

bool isQueueEmpty(Queue pointer)
{
    return !pointer.head;
}

bool onTopOfQueue(int *data, Queue pointer)
{
    if(!isQueueEmpty(pointer))
    {
        *data = pointer.head->data;
        return true;
    }
    return false;
}

void clearQueue(Queue *pointer)
{
    while(pointer->head)
        popFromQueue(pointer);
    pointer->tail = NULL;
}



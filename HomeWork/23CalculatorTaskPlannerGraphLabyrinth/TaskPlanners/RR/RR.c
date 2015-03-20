#include "RR.h"

// ---QUEUE---

void initializeQueue(Queue *pointer)
{
    pointer->head = NULL;
    pointer->tail = NULL;
}

bool addToQueue(Process data, Queue *pointer)
{
    RunningNode *temp = NULL;
    temp = (RunningNode *)malloc(sizeof(RunningNode));
    if(temp == NULL)
    {
        return false;
    }
    temp->process = data;
    temp->link = pointer->head;

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
        RunningNode *temp = pointer->head;
        pointer->head = pointer->head->link;
        pointer->tail->link = pointer->head;
        temp->process.identifier = 0;
        temp->process.comingTime = 0;
        temp->process.runningTime = 0;
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

void onHeadOfQueue(Process *process, Queue pointer)
{
    if(pointer.head)
        *process = pointer.head->process;
}

// ---LISTS---

bool addToListOfUnbornProcesses(Process data, ListOfUnbornProcesses *pointer)
{
    RunningNode *temp1 = NULL, *temp2 = *pointer;
    temp1 = (RunningNode *)malloc(sizeof(RunningNode));
    if(temp1 == NULL)
        return false;
    temp1->process = data;
    if(temp2 == NULL)
    {
        temp1->link = NULL;
        *pointer = temp1;
    }
    else if(temp2->process.comingTime > temp1->process.comingTime)
    {
        temp1->link = temp2;
        *pointer = temp1;
    }
    else
    {
        while(temp2->link && temp2->link->process.comingTime < temp1->process.comingTime)
            temp2 = temp2->link;
        temp1->link = temp2->link;
        temp2->link = temp1;
    }
    return true;
}

void deleteFromListOfUnbornProcesses(ListOfUnbornProcesses *pointer)
{
    if(*pointer)
    {
        RunningNode *temp = *pointer;
        *pointer = (*pointer)->link;
        temp->process.identifier = 0;
        temp->process.runningTime = 0;
        temp->process.comingTime = 0;
        temp->link = NULL;
        free(temp);
        temp = NULL;
    }
}

void onHeadOfUnbornProcessesList(Process *process, ListOfUnbornProcesses pointer)
{
    if(pointer)
        *process = pointer->process;
}

// ---

bool addToListOfRunnedParts(RunnedProcess data, ListOfRunnedPartsOfProcesses *pointer)
{
    RunnedNode *newData = NULL, *tempPointer = *pointer;

    newData = (RunnedNode *)malloc(sizeof(RunnedNode));
    if(newData == NULL)
        return false;
    newData->runnedProcess = data;
    newData->link = NULL;

    if(tempPointer == NULL)
        *pointer = newData;
    else
    {
        while(tempPointer->link)
            tempPointer = tempPointer->link;
        tempPointer->link = newData;
    }

    newData = NULL;
    return true;
}

void clearTheListOfRunnedProcesses(ListOfRunnedPartsOfProcesses *pointer)
{
    RunnedNode *tempPointer = *pointer;
    while(*pointer)
    {
        tempPointer = (*pointer)->link;
        free(*pointer);
        *pointer = tempPointer;
    }
}


#include "Queue.h"

void initializeQueue(Queue *pointer)
{
    pointer->head = NULL;
    pointer->tail = NULL;
}

bool addToQueue(Data data, Queue *pointer)
{
    Node *newData = NULL;

    newData = (Node*)malloc(sizeof(Node));
    if(newData == NULL)
        return false;

    newData->data = data;
    newData->link = pointer->head;

    pointer->head = newData;
    if(!pointer->tail)
        pointer->tail = pointer->head;

    newData = NULL;
    return true;
}

void removeFromQueue(Queue *pointer)
{
    if(pointer->tail)
    {
        Node *temp = pointer->head;
        while(temp->link != pointer->tail)
        {
            temp = temp->link;
        }
        temp->link = NULL;
        strcpy(pointer->tail->data.name, "");
        pointer->tail->data.area = 0;
        free(pointer->tail);
        pointer->tail = temp;
    }
}

int amountOfNodesInQueue(const Queue pointer)
{
    int counter = 0;
    Node *temp = pointer.head;
    while(temp)
    {
        ++counter;
        temp = temp->link;
    }
    return counter;
}

bool isEmpty(const Queue pointer)
{
    return pointer.head == NULL;
}

bool isFull(const Queue pointer)
{
    bool indicator;
    Node *test = (Node *)malloc(sizeof(Node));
    if(!test)
        indicator = true;
    else
        indicator = false;
    free(test);
    test = NULL;
    return indicator;
}

void workOnNodes(const Queue pointer, void (*function)(Data))
{
    Node *temp = pointer.head;
    while(temp)
    {
        function(temp->data);
        temp = temp->link;
    }
}

void clearQueue(Queue *pointer)
{
    Node *temp = pointer->head;
    while(pointer->head)
    {
        temp = pointer->head->link;
        free(pointer->head);
        pointer->head = NULL;
        pointer->head = temp;
    }
    pointer->tail = NULL;
}

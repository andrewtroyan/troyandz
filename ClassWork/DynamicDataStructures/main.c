#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Динамические структуры данных (списки, деревья, графы).

typedef struct Anything_
{
    int x;
    struct Anything_ *s;
} Anything;

typedef int Data;

typedef struct Node_
{
    Data data;
    struct Node_ *link; //*link - структура односвязная; (*next, *previous) - двухсвязная, линейная; (*left, *right, *parent) - дерево;
} Node;

void push(Node **top, Data data);
void pop(Node **top);
bool onTop(Node *top, Data *data);
bool isEmpty(Node *top);
void clear(Node **top);

int main()
{
    //Node *top; // top - локальная переменная ("на земле");

    //push(&top, 27);

    return 0;
}

void push(Node **top, Data data)
{
    Node *p = NULL;                   // 1
    p = (Node *)malloc(sizeof(Node)); // этап

    p->data = data; // 2
    p->link = *top; // этап

    *top = p;  // 3
    p = NULL;  // этап
}

void pop(Node **top)
{
    if(*top)
    {
        Node *p = *top;
        *top = (*top)->link; // (**top).link

        p->data = 0;
        p->link = NULL;

        free(p);
        p = NULL;
    }
}

bool onTop(Node *top, Data *data)
{
    if(!top)
        return false;
    *data = top->data;
    return true;
}

bool isEmpty(Node *top)
{
    return top == NULL;
}

void clear(Node **top)
{
    while(*top)
        pop(top);
}

#include "../include/myStack.h"

void push(int *stack, int size, int *top, int datum)
{
    assert(*top < size - 1);
    stack[++(*top)] = datum;
}

int pop(int *stack, int *top)
{
    assert(*top > -1);
    return stack[(*top)--];
}

void onTop(int size, int *top, int datum)
{
    assert(datum > -1 && datum < size);
    *top = datum;
}

void isEmpty(int *stack, int size, int *top)
{
    for(int i = 0; i < size; ++i)
    {
        stack[i] = 0;
    }
    *top = -1;
}

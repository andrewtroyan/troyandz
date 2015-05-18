#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include <assert.h>

void push(int *stack, int size, int *top, int datum);
int pop(int *stack, int *top);
void onTop(int size, int *top, int datum);
void isEmpty(int *stack, int size, int *top);

#endif // MYSTACK_H_INCLUDED

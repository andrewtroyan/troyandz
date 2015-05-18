#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define SIZE 1000

int main()
{
    char stack[SIZE], symbol;
    do
    {
        symbol = getchar();
        if(symbol == '(' || symbol == '[' || symbol == '{')
        {
            push(stack, symbol);
        }
        else if(symbol == ')' || symbol == ']' || symbol == '}')
        {
            pop(stack);
        }
    }while(symbol != '\n');
    showCheckedStack(stack);
    return 0;
}


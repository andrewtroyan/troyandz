#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int stack[SIZE];
    char symbol;
    while(symbol != '=')
    {
        symbol = getchar();
        switch (symbol)
        {
        case '+':
            add(stack);
            break;
        case '-':
            deduct(stack);
            break;
        case '*':
            multiply(stack);
            break;
        case '/':
            divide(stack);
            break;
        case '=':
            break;
        default:
            push(stack, symbol);
        }
    }
    printResult(stack);
    return 0;
}

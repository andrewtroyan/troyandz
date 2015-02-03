#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    char stack[SIZE], symbol;
    do
    {
        symbol = getchar();
        if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
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
            }
        }
        else
        {
            push(stack, symbol);
        }
    }while(symbol != '=');
    printResult(stack);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int main()
{
    char stack[SIZE], symbol;
    int top = -1, result = 0;
    do
    {
        symbol = getchar();
        if(symbol >= 48 && symbol <= 57)
        {
            stack[++top] = symbol;
        }
        else
        {
            switch (symbol)
            {
            case '+':
                stack[top--] = 0;
                result = stack[top--] + stack[top];
                stack[top] = result;
                break;
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
            }
        }
    }while(symbol != '=');
    printf("%c", stack[top]);
    return 0;
}

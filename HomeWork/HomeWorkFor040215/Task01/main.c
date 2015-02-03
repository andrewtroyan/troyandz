#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int main()
{
    char stack[SIZE], symbol;
    int top = -1;
    do
    {
        symbol = getchar();
        if(symbol == '(' || symbol == '[' || symbol == '{')
        {
            stack[++top] = symbol;
        }
        else if(symbol == ')' || symbol == ']' || symbol == '}')
        {
            stack[top--] = 0;
        }
    }while(symbol != '\n');
    if(stack[top] == 0)
    {
        printf("Correctly.");
    }
    else
    {
        printf("Incorrectly.");
    }
    return 0;
}


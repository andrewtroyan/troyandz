static int top = -1;

void push(char stack[], char symbol)
{
    stack[++top] = symbol;
}

void pop(char stack[])
{
    stack[top--] = 0;
}

int checkStack(char stack[])
{
    return stack[top] == 0? 0 : 1;
}

void showCheckedStack(char stack[])
{
    if(checkStack(stack) == 0)
    {
        printf("Correctly!");
    }
    else
    {
        printf("Incorrectly!");
    }
}

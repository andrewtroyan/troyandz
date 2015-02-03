static int top = -1;
int result;

void push(char stack[], char symbol)
{
    stack[++top] = symbol;
}

int pop(char stack[])
{
    int result = stack[top] - '0';
    stack[top--] = 0;
    return result;
}

void add(char stack[])
{
    result = pop(stack) + pop(stack);
    stack[++top] = result;
}

void deduct(char stack[])
{
    result = -1 * pop(stack);
    result += pop(stack);
    stack[++top] = result;
}

void multiply(char stack[])
{
    result = pop(stack) * pop(stack);
    stack[++top] = result;
}

void divide(char stack[])
{
    result = pop(stack);
    result = pop(stack) / result;
    stack[++top] = result;
}

void printResult(char stack[])
{
    printf("%d", result);
}



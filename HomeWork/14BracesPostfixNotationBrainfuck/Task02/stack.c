static int top = -1;

void push(int stack[], char symbol)
{
    stack[++top] = symbol - '0';
}

int pop(int stack[])
{
    int result = stack[top];
    stack[top--] = 0;
    return result;
}

void add(int stack[])
{
    int result = pop(stack) + pop(stack);
    stack[++top] = result;
}

void deduct(int stack[])
{
    int result = -1 * pop(stack);
    result += pop(stack);
    stack[++top] = result;
}

void multiply(int stack[])
{
    int result = pop(stack) * pop(stack);
    stack[++top] = result;
}

void divide(int stack[])
{
    int result = pop(stack);
    result = pop(stack) / result;
    stack[++top] = result;
}

void printResult(int stack[])
{
    printf("%d", stack[top]);
}



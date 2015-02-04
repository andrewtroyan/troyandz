static int top = -1;
int result;

void push(int stack[], int symbol)
{
    stack[++top] = symbol;
}

int pop(int stack[])
{
    int result = stack[top] - '0';
    stack[top--] = 0;
    return result;
}

void add(int stack[])
{
    result = pop(stack) + pop(stack);
    stack[++top] = result;
}

void deduct(int stack[])
{
    result = -1 * pop(stack);
    result += pop(stack);
    stack[++top] = result;
}

void multiply(int stack[])
{
    result = pop(stack) * pop(stack);
    stack[++top] = result;
}

void divide(int stack[])
{
    result = pop(stack);
    result = pop(stack) / result;
    stack[++top] = result;
}

void printResult(int stack[])
{
    printf("%d", result);
}



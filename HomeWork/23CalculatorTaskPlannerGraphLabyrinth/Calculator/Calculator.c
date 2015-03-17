#include "Calculator.h"

int getPriority(char sign)
{
    if(sign == '(' || sign == ')')
        return 0;
    else if(sign == '+' || sign == '-')
        return 1;
    else if(sign == '*' || sign == '/')
        return 2;
    else if(sign == '^')
        return 3;
    else
    {
        fprintf(stderr, "Invalid character.\n");
        exit(1);
    }
}

void setAsNumber(Item *pointer, float number)
{
    pointer->number = number;
    pointer->sign = 0;
    pointer->indicator = num;
}

void setAsOperator(Item *pointer, char sign)
{
    pointer->number = 0;
    pointer->sign = sign;
    pointer->indicator = symbol;
}

void initializeList(List *pointer)
{
    *pointer = NULL;
}

bool addToList(Item data, List *pointer)
{
    List newData, tempPointer = *pointer;

    newData = (List)malloc(sizeof(Node));
    if(newData == NULL)
        return false;
    newData->data = data;
    newData->link = NULL;

    if(tempPointer == NULL)
        *pointer = newData;
    else
    {
        while(tempPointer->link != NULL)
            tempPointer = tempPointer->link;
        tempPointer->link = newData;
    }

    newData = NULL;
    return true;
}

void clearTheList(List *pointer)
{
    List tempPointer = *pointer;
    while(*pointer != NULL)
    {
        tempPointer = (*pointer)->link;
        free(*pointer);
        *pointer = tempPointer;
    }
}

void initializeStack(Stack *top)
{
    *top = NULL;
}

void push(Item item, Stack *top)
{
    Stack temp = NULL;
    temp = (Stack)malloc(sizeof(Node));
    if(temp == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    temp->data = item;
    temp->link = *top;

    *top = temp;
    temp = NULL;
}

void pop(Stack *top)
{
    if(*top)
    {
        Stack temp = *top;
        *top = (*top)->link;

        temp->data.number = 0;
        temp->data.sign = 0;
        temp->data.indicator = null;

        temp->link = NULL;

        free(temp);
        temp = NULL;
    }
}

bool onTop(Item *item, Stack top)
{
    if(!top)
        return false;
    *item = top->data;
    return true;
}

void clearStack(Stack *top)
{
    while(*top)
        pop(top);
}

void workOnNodes(List list, Stack *stack, void (*function)(Item item, Stack *stack))
{
    List temp = list;
    while(temp)
    {
        function(temp->data, stack);
        temp = temp->link;
    }
}

void workOnEveryNode(Item item, Stack *stack)
{
    if(item.indicator == num)
    {
        push(item, stack);
    }
    else if(item.indicator == symbol)
    {
        workOnOperator(item.sign, stack);
    }
}

void workOnOperator(char sign, Stack *stack)
{
    Item firstNumber, secondNumber, result = {0, 0, num};
    onTop(&firstNumber, *stack);
    pop(stack);
    onTop(&secondNumber, *stack);
    pop(stack);

    switch(sign)
    {
    case '-':
        result.number = secondNumber.number - firstNumber.number;
        break;
    case '+':
        result.number = firstNumber.number + secondNumber.number;
        break;
    case '*':
        result.number = firstNumber.number * secondNumber.number;
        break;
    case '/':
        result.number = secondNumber.number - firstNumber.number;
        break;
    case '^':
        result.number = pow(secondNumber.number, firstNumber.number);
        break;
    }

    push(result, stack);
}

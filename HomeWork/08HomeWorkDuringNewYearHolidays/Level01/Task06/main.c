#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber, secondNumber, result = 0;
    char operation;
    scanf("%d%c%d", &firstNumber, &operation, &secondNumber);
    switch (operation)
    {
    case '+':
        result = firstNumber + secondNumber;
        break;
    case '-':
        result = firstNumber - secondNumber;
        break;
    case '*':
        result = firstNumber * secondNumber;
        break;
    case '/':
        result = firstNumber / secondNumber;
    }
    system("cls");
    printf("%d", result);
    return 0;
}

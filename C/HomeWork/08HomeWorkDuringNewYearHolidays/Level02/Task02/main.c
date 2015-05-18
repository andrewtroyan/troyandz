#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber, secondNumber, result;
    char operation;
    do
    {
        system("cls");
        scanf("%d", &firstNumber);
        result = firstNumber;
        do
        {
            scanf(" %c", &operation);
            switch (operation)
            {
            case '+':
                scanf("%d", &secondNumber);
                result += secondNumber;
                break;
            case '-':
                scanf("%d", &secondNumber);
                result -= secondNumber;
                break;
            case '*':
                scanf("%d", &secondNumber);
                result *= secondNumber;
                break;
            case '/':
                scanf("%d", &secondNumber);
                result /= secondNumber;
                break;
            case '=':
                for (int i = 1; i <= 2000; ++i)
                {
                    printf("%d\r", result);
                }
                break;
            }
        } while (operation != '=' && operation != 'c' && operation != 'e');
    } while (operation == 'c' || operation == '=');
    return 0;
}

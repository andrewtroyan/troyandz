#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, exponent;
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    int result=number;
    for (int i=0; i==exponent; ++i) /* Изначально проверяем. Если степень равна 0, то результатом будет 1.
                                      ++i пишем для того, чтобы цикл завершился. */
    {
        result=1;
    }
    for (int i=1; i<exponent; ++i) /* Грубо говоря, этот цикл работает при степени >= 2. Для степени 1 изначально
                                    выполняется действие int result=number; */
    {
        int squared = 0;
        for (int k=0; k<number; ++k)
            {
                squared+=result;
            }
        result=squared;
    }
    printf("The result is %d", result);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int L, number, exponent = 0, result = 1;
    printf("Enter the number > 0: ");
    scanf("%d", &L);
    printf("Enter the number <= the previous number: ");
    scanf("%d", &number);
    do
    {
        result*=number;
        ++exponent;
    } while(result <= L);
    printf("%d ^ %d is closest to %d", number, exponent - 1, L);
    return 0;
}


/* Цикл for используем, когда вводим счетчик. Этот цикл выполняется
   определенное количество раз (пока действует счетчик).

   While используем, когда наш цикл может выполняться неопределенное
   количество раз (пока действие внутри цикла удовлетворяет условие). */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number1Abs, number1, sumOfNumerals1 = 0;   //Пользователь вводит число. Мы это число присваиваем двум переменным
    printf("Enter the number >= 1: ");             //для того, чтобы одна переменная оставалась неизменной, а над второй
    scanf("%d", &number1Abs);                      //мы работали.
    int decades = 1;
    number1 = number1Abs;
    while (decades <= number1)
    {
        decades *= 10;
    }
    while (number1)
    {
        while(decades > number1)
        {
            decades /= 10;
        }
        sumOfNumerals1 += number1/decades;
        number1 %= decades;
    }

    int number2Abs = number1Abs, number2, sumOfNumerals2; //Так же заводим две переменные (статическую и динамическую)
    do                                                    //для числа, которое сначала равно первому числу.
    {
        decades = 1;                                      //Каждый раз обновляем показатель десятков.
        sumOfNumerals2 = 0;                               //Каждый раз обновляем сумму цифр второго числа.
        number2Abs += 9;                                  //Каждый раз добавляем ко второму числу 9.
        number2 = number2Abs;                             //И присваиваем динамической переменной новое значение статической переменной.
        while (decades <= number2)
        {
            decades *= 10;
        }
        while (number2)
        {
            while(decades > number2)
            {
                decades /= 10;
            }
            sumOfNumerals2 += number2/decades;
            number2 %= decades;
        }
    } while (sumOfNumerals1 != sumOfNumerals2);          //До тех пор, пока суммы цифр двух чисел не будут равны между собой.

    printf("The next number after %d with the same sum of numerals is %d.", number1Abs, number2Abs);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number1Abs, number1, sumOfNumerals1 = 0;   //Пользователь вводит число. Мы это число присваиваем двум переменным
    printf("Enter the number >= 1: ");             //для того, чтобы одна переменная оставалась неизменной, а над второй
    scanf("%d", &number1Abs);                      //мы работали.
    number1 = number1Abs;
    while (number1)
    {
        sumOfNumerals1 += number1 % 10;
        number1 /= 10;
    }

    int number2Abs = number1Abs, number2, sumOfNumerals2; //Так же заводим две переменные (статическую и динамическую)
    do                                                    //для числа, которое сначала равно первому числу.
    {
        sumOfNumerals2 = 0;                               //Каждый раз обновляем сумму цифр второго числа.
        number2Abs += 9;                                  //Каждый раз добавляем ко второму числу 9.
        number2 = number2Abs;                             //И присваиваем динамической переменной новое значение статической переменной.
        while (number2)
        {
            sumOfNumerals2 += number2 % 10;
            number2 /= 10;
        }
    } while (sumOfNumerals1 != sumOfNumerals2);          //До тех пор, пока суммы цифр двух чисел не будут равны между собой.

    printf("The next number after %d with the same sum of numerals is %d.", number1Abs, number2Abs);
    return 0;
}

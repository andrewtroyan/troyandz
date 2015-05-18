#include "QsortDetails.h"

int sumOfDigits(int number)
{
    int result = 0;
    while(number)
    {
        result += number % 10;
        number /= 10;
    }
    return result;
}

int amountOfDividers(int number)
{
    int result = 2;
    for(int i = 2; i <= number / 2; ++i)
    {
        if(number % i == 0)
        {
            ++result;
        }
    }
    return result;
}

int functionForQsort(const void *a, const void *b)
{
    //return *((const int *)b) - *((const int *)a);
    //по убыванию
    //return sumOfDigits(*((const int *)a)) - sumOfDigits(*((const int *)b));
    //по возрастанию суммы цифр
    return amountOfDividers(*((const int *)a)) - amountOfDividers(*((const int *)b));
    //по возрастанию количества делителей
}

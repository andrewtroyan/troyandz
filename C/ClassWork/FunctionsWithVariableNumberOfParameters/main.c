#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h> //cstdarg in C++

// va_list (variable arguments list)

//Переменное число параметров - всегда последний параметр в функции).

int findMax(int n, ...)
{
    int largest;
    va_list theList; //список переменного числа параметров
    va_start(theList, n); //это не значение n, которое мы передали. Это любой параметр в нашей функции.
    largest = va_arg(theList, int); //с int опасность, потому что могли в функции передать не int
    for(int i = 1; i < n; ++i)
    {
        int val = va_arg(theList, int);
        largest = (largest > val)? largest : val;
    }
    va_end(theList);
    return largest;
}

int main()
{
    int max = findMax(3, 1, 2, -1);
    printf("%d", max);
    return 0;
}

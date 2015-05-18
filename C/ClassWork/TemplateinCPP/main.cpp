#include <iostream>

//Функциональные макросы
//#define ABS(x) x<0?-x:x неправильно
//ABS(3);
//3<0?-3:3;
//ABS(5 - 7);
//5-7<0?-5-7:5-7
//#define ABS(x) (x)<0?-(x):(x)

template <typename T> //можно написать вместо template class. Это НЕ ФУНКЦИЯ.
T abs(T x)
{
    return x < 0? -x : x;
}

//Инстанцирование шаблона - это когда кто-нибудь захочет позвать, например:
//int a, b;
//b = abs(a);

//float x, y;
//y = abs(x);

//Шаблон должен быть помещен в заголовочный файл ЦЕЛИКОМ.

template <typename T>
void Swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <>
void Swap<int> (int &x, int &y)
{
    x ^= y;
    y ^= x;
    x ^= y;
}

template <int n> //факториал времени компиляции
int f()
{
    return n * f<n - 1>();
}

template<>
int f<0>()
{
    return 1;
}

using namespace std;

int main()
{
    cout << abs(-100) << endl << abs(-3.14) << endl;

    double x, y;
    swap(x, y);

    int a, b;
    Swap(a, b);

    long long int c;
    c = abs<long long int>(a);

    const int z = f<7>();
    cout << z << endl;

    return 0;
}


#include <stdlib.h>
#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif // defined

void universalClear()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__linux__)
    system("clear");
#else
#error undefined operating system
#endif // defined
}

void universalSleep(double time)
{
#if defined(_WIN32) || defined(_WIN64)
    Sleep(time * 1000);
#elif defined(__linux__)
    char str[128];
    sprintf(str, "sleep %f", time);
    system(str);
#else
#error undefined operating system
#endif // defined
}

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    unsigned char string[SIZE] = {0};
    int direction = 0;
    char symbol;
    while(symbol != ';')
    {
        symbol = getchar();
        switch(symbol)
        {
        case '+':
            ++string[direction];
            break;
        case '-':
            --string[direction];
            break;
        case '>':
            ++direction;
            break;
        case '<':
            --direction;
            break;
        case '.':
            putchar(string[direction]);
            break;
        }
    }
    return 0;
}

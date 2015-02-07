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
            printf("%c", string[direction]);
        }
    }
    return 0;
}

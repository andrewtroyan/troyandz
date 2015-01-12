#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printRhombus(int ident, int width);

int main()
{
    printRhombus(3, 3);
    printRhombus(0, 9);
    printRhombus(3, 3);
    printRhombus(1, 7);
    printRhombus(3, 3);
    printRhombus(0, 9);
    printRhombus(3, 3);
    return 0;
}

void printRow (int ident, int width, int i);

void printRhombus(int ident, int width)
{
    assert(width % 2 == 1);
    for (int i = 1; i <= width; i += 2)
    {
        printRow(ident, width, i);
    }
    for (int i = width - 2; i >= 1; i -= 2)
    {
        printRow(ident, width, i);
    }
}

void printRow (int ident, int width, int i)
{
    for (int j = 1; j <= (width - i) / 2 + ident; ++j)
    {
        printf(" ");
    }
    for (int j = 1; j <= i; ++j)
    {
        printf("#");
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/compatibility.h"
#include "brainFuck.h"

int main()
{
    unsigned char string[SIZE] = {0};
    char symbols[SIZE] = {0};
    fillArrayWithSymbols(symbols, SIZE);
    universalClear();
    runTheProgram(symbols);
    return 0;
}

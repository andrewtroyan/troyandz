#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../Modules/include/UTF8Functions.h"

int main()
{
    char *string = "Привет!";
    printf("%x\n", string[1]);
    return 0;
}

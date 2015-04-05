#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../Modules/include/UTF8Functions.h"

int main()
{
    char *string = "Привет!";
//    for(int i = 0; string[i]; ++i)
//        printf("%x\n", string[i]);
    printf("%d\n", string[1]);
    return 0;
}

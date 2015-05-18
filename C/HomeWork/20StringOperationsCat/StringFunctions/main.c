#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/myString.h"

int main()
{
    char string1[100] = "Hello world!";
    printf("\"%s\" - this string contains %d characters.\n", string1, myStrlen(string1));

    char string2[100] = "Hello!";
    if(myStrcmp(string1, string2) == 0)
    {
        printf("\"%s\" and \"%s\" are equal.\n", string1, string2);
    }
    else
    {
        printf("\"%s\" and \"%s\" are not equal.\n", string1, string2);
    }

    printf("\"%s\" - I copied the second phrase to the first.\n", myStrcpy(string1, string2));
    return 0;
}
